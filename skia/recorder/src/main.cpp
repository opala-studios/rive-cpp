#define SK_GL
#include "GLFW/glfw3.h"

#include "GrBackendSurface.h"
#include "GrContext.h"
#include "SkCanvas.h"
#include "SkColorSpace.h"
#include "SkSurface.h"
#include "SkTypes.h"
#include "gl/GrGLInterface.h"

#include "animation/linear_animation_instance.hpp"
#include "artboard.hpp"
#include "file.hpp"
#include "layout.hpp"
#include "math/aabb.hpp"
#include "skia_renderer.hpp"

#include <cmath>
#include <stdio.h>
#include <string>

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/dict.h>
#include <libavutil/mathematics.h>
#include <libavutil/opt.h>
#include <libavutil/pixfmt.h>
#include <libswscale/swscale.h>
#include <x264.h>
}

rive::File* currentFile = nullptr;
rive::Artboard* artboard = nullptr;
rive::LinearAnimationInstance* animationInstance = nullptr;
int width = 256, height = 256;

void glfwErrorCallback(int error, const char* description)
{
	puts(description);
}

std::string getFileName(char* path)
{
	std::string str(path);

	const size_t from = str.find_last_of("\\/");
	const size_t to = str.find_last_of(".");
	return str.substr(from + 1, to - from - 1);
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "must pass source file");
		return 1;
	}
	FILE* fp = fopen(argv[1], "r");

	const char* outPath;
	std::string filename;
	filename = getFileName(argv[1]);

	fseek(fp, 0, SEEK_END);
	auto length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	uint8_t* bytes = new uint8_t[length];
	if (fread(bytes, 1, length, fp) != length)
	{
		fprintf(stderr, "Failed to read rive file.\n");
		return 1;
	}

	auto reader = rive::BinaryReader(bytes, length);
	rive::File* file = nullptr;
	auto result = rive::File::import(reader, &file);
	if (result != rive::ImportResult::success)
	{
		fprintf(stderr, "Failed to read rive file.\n");
		return 1;
	}
	artboard = file->artboard();
	auto animation = artboard->firstAnimation<rive::LinearAnimation>();
	if (animation != nullptr)
	{
		animationInstance = new rive::LinearAnimationInstance(animation);
	}
	artboard->advance(0.0f);

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize glfw.\n");
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLFWwindow* window =
	    glfwCreateWindow(1280, 720, "Rive Recorder", NULL, NULL);
	if (window == nullptr)
	{
		fprintf(stderr, "Failed to make window or GL.\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);
	// Enable VSYNC.
	glfwSwapInterval(1);

	// Setup Skia
	GrContextOptions options;
	sk_sp<GrContext> context = GrContext::MakeGL(nullptr, options);
	GrGLFramebufferInfo framebufferInfo;
	framebufferInfo.fFBOID = 0;
	framebufferInfo.fFormat = GL_RGBA8;

	SkSurface* surface = nullptr;
	SkCanvas* canvas = nullptr;

	// Render loop.

	int lastScreenWidth = 0, lastScreenHeight = 0;
	int frame = 0;
	double lastTime = glfwGetTime();
	int targetLoops = 2;
	int loops = 0;
	// fps = 60;

	// INITIALIZE VID
	av_register_all(); // Loads the whole database of available codecs and
	                   // formats.

	fprintf(stderr, "1\n");
	struct SwsContext* convertCtx = sws_getContext(
	    width,
	    height,
	    AV_PIX_FMT_RGB24,
	    width,
	    height,
	    AV_PIX_FMT_YUV420P,
	    SWS_FAST_BILINEAR,
	    NULL,
	    NULL,
	    NULL); // Preparing to convert my generated RGB images to YUV frames.

	// Preparing the data concerning the format and codec in order to write
	// properly the header, frame data and end of file.
	const char* fmtext = "mp4";
	char* filename2;
	sprintf(filename2, "GeneratedVideo.%s", fmtext);
	AVOutputFormat* fmt = av_guess_format(fmtext, NULL, NULL);
	AVFormatContext* oc = NULL;
	avformat_alloc_output_context2(&oc, NULL, NULL, filename2);
	AVStream* stream = avformat_new_stream(oc, 0);
	AVCodec* codec = NULL;
	AVCodecContext* c = NULL;
	int ret;
	fprintf(stderr, "2\n");
	codec = avcodec_find_encoder_by_name("libx264");

	printf("Address of x is %p\n", (void*)codec);
	fprintf(stderr, "2.1\n");

	// Setting up the codec:
	AVDictionary* opt = NULL;
	fprintf(stderr, "2.1.1\n");
	av_dict_set(&opt, "preset", "slow", 0);

	fprintf(stderr, "2.2\n");
	av_dict_set(&opt, "crf", "20", 0);
	avcodec_get_context_defaults3(stream->codec, codec);
	c = avcodec_alloc_context3(codec);
	fprintf(stderr, "2.3\n");
	c->width = width;
	c->height = height;
	c->pix_fmt = AV_PIX_FMT_YUV420P;

	// Setting up the format, its stream(s), linking with the codec(s) and write
	// the header:
	fprintf(stderr, "2.4\n");
	if (oc->oformat->flags &
	    AVFMT_GLOBALHEADER) // Some formats require a global header.
		c->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;

	avcodec_open2(c, codec, &opt);
	av_dict_free(&opt);
	fprintf(stderr, "2.5\n");
	stream->time_base = (AVRational){1, 25};
	stream->codec =
	    c; // Once the codec is set up, we need to let the container know which
	       // codec are the streams using, in this case the only (video) stream.
	av_dump_format(oc, 0, filename2, 1);
	avio_open(&oc->pb, filename2, AVIO_FLAG_WRITE);
	ret = avformat_write_header(oc, &opt);
	av_dict_free(&opt);
	fprintf(stderr, "3\n");
	// Preparing the containers of the frame data:
	AVFrame *rgbpic, *yuvpic;

	// Allocating memory for each RGB frame, which will be lately converted to
	// YUV:
	rgbpic = av_frame_alloc();
	rgbpic->format = AV_PIX_FMT_RGB24;
	rgbpic->width = width;
	rgbpic->height = height;
	ret = av_frame_get_buffer(rgbpic, 1);

	// Allocating memory for each conversion output YUV frame:
	yuvpic = av_frame_alloc();
	yuvpic->format = AV_PIX_FMT_YUV420P;
	yuvpic->width = width;
	yuvpic->height = height;
	ret = av_frame_get_buffer(yuvpic, 1);
	fprintf(stderr, "4\n");
	int got_output;
	AVPacket pkt;
	while (!glfwWindowShouldClose(window) && loops < targetLoops)
	{
		fprintf(stderr, "oh?\n");
		glfwGetFramebufferSize(window, &width, &height);

		// Update surface.
		if (surface == nullptr || width != lastScreenWidth ||
		    height != lastScreenHeight)
		{
			lastScreenWidth = width;
			lastScreenHeight = height;

			SkColorType colorType =
			    kRGBA_8888_SkColorType; // GrColorTypeToSkColorType(GrPixelConfigToColorType(kRGBA_8888_GrPixelConfig));
			//
			// if (kRGBA_8888_GrPixelConfig == kSkia8888_GrPixelConfig)
			// {
			// 	colorType = kRGBA_8888_SkColorType;
			// }
			// else
			// {
			// 	colorType = kBGRA_8888_SkColorType;
			// }

			GrBackendRenderTarget backendRenderTarget(width,
			                                          height,
			                                          0, // sample count
			                                          0, // stencil bits
			                                          framebufferInfo);

			delete surface;
			surface = SkSurface::MakeFromBackendRenderTarget(
			              context.get(),
			              backendRenderTarget,
			              kBottomLeft_GrSurfaceOrigin,
			              colorType,
			              nullptr,
			              nullptr)
			              .release();
			if (surface == nullptr)
			{
				fprintf(stderr, "Failed to create Skia surface\n");
				return 1;
			}
			canvas = surface->getCanvas();
		}

		double time = glfwGetTime();
		float elapsed = (float)(time - lastTime);
		lastTime = time;

		// Clear screen.
		SkPaint paint;
		paint.setColor(SK_ColorDKGRAY);
		canvas->drawPaint(paint);

		if (artboard != nullptr)
		{

			if (animationInstance != nullptr)
			{
				animationInstance->advance(elapsed);
				if (animationInstance->didLoop())
				{
					loops += 1;
				}
				animationInstance->apply(artboard);
			}
			artboard->advance(elapsed);

			rive::SkiaRenderer renderer(canvas);
			renderer.save();
			renderer.align(rive::Fit::contain,
			               rive::Alignment::center,
			               rive::AABB(0, 0, width, height),
			               artboard->bounds());
			artboard->draw(&renderer);
			renderer.restore();
		}

		context->flush();
		// and lets do some file writing cos we can.
		int width = 256, height = 256;

		sk_sp<SkSurface> rasterSurface =
		    SkSurface::MakeRasterN32Premul(width, height);
		SkCanvas* rasterCanvas = rasterSurface->getCanvas();

		rive::SkiaRenderer renderer(rasterCanvas);
		renderer.save();
		renderer.align(rive::Fit::cover,
		               rive::Alignment::center,
		               rive::AABB(0, 0, width, height),
		               artboard->bounds());
		artboard->draw(&renderer);
		renderer.restore();

		sk_sp<SkImage> img(rasterSurface->makeImageSnapshot());
		if (!img)
		{
			return 1;
		}
		fprintf(stderr, "hah!");
		sk_sp<SkData> png(img->encodeToData(SkEncodedImageFormat::kPNG, 100));
		if (!png)
		{
			fprintf(stderr, "oh no!");
			return 1;
		}

		outPath = (filename + "." + std::to_string(frame) + ".png").c_str();
		SkFILEWStream out(outPath);

		(void)out.write(png->data(), png->size());
		fprintf(stderr, "IS IT NOT WRITTEN??\n");

		glfwSwapBuffers(window);
		glfwPollEvents();

		int x, y, i;
		int size = png->size();
		fprintf(stderr, "PNG Size %d %d\n", png->size());
		for (i = 0; i < size; i++)
		{
			auto fuck = png->bytes();
			// fprintf(stderr, "wat %d %d\n", i, &fuck[i]);
		}
		// // for (y = 0; y < height; y++)
		// // {
		// // 	for (x = 0; x < width; x++)
		// // 	{
		// // 		// rgbpic->linesize[0] is equal to width.
		// // 		rgbpic->data[0][y * rgbpic->linesize[0] + 3 * x] = 0;
		// // 		rgbpic->data[0][y * rgbpic->linesize[0] + 3 * x + 1] =
		// 1;
		// // 		rgbpic->data[0][y * rgbpic->linesize[0] + 3 * x + 2] =
		// 2;
		// // 	}
		// // }
		// fprintf(stderr, "joke?\n");
		// avpicture_fill((AVPicture*)&yuvpic,
		//                png->bytes(),
		//                AV_PIX_FMT_YUV420P,
		//                width,
		//                height);
		// fprintf(stderr, "dun something?\n");
		// // sws_scale(convertCtx,
		// //           rgbpic->data,
		// //           rgbpic->linesize,
		// //           0,
		// //           height,
		// //           yuvpic->data,
		// //           yuvpic->linesize); // Not actually scaling anything,
		// but
		// //           just
		// //                              // converting the RGB data to YUV
		// and
		// //                              store
		// // it in yuvpic.
		// fprintf(stderr, "dun something else?\n");
		av_init_packet(&pkt);
		pkt.data = NULL;
		pkt.size = 0;
		yuvpic->pts = frame; // The PTS of the frame are just in a reference

		fprintf(stderr, "no way?\n");
		ret = avcodec_encode_video2(c, &pkt, yuvpic, &got_output);
		fprintf(stderr, "encoded??\n");
		// if (got_output)
		// {
		// 	fprintf(stderr, "what?\n");
		// 	fflush(stdout);
		// 	av_packet_rescale_ts(
		// 	    &pkt,
		// 	    (AVRational){1, 25},
		// 	    stream->time_base); // We set the packet PTS and DTS taking in
		// 	                        // the account our FPS (second argument) and
		// 	                        // the time base that our selected format
		// 	                        // uses (third argument).
		// 	pkt.stream_index = stream->index;
		// 	printf("Write frame %6d (size=%6d)\n", frame, pkt.size);
		// 	av_interleaved_write_frame(
		// 	    oc, &pkt); // Write the encoded frame to the mp4 file.
		// 	av_packet_unref(&pkt);
		// }
		frame += 1;
	}

	fprintf(stderr, "OH?\n");

	// Writing the delayed frames:
	for (got_output = 1; got_output; frame++)
	{
		ret = avcodec_encode_video2(c, &pkt, NULL, &got_output);
		if (got_output)
		{
			fflush(stdout);
			av_packet_rescale_ts(&pkt, (AVRational){1, 25}, stream->time_base);
			pkt.stream_index = stream->index;
			printf("Write frame %6d (size=%6d)\n", frame, pkt.size);
			av_interleaved_write_frame(oc, &pkt);
			av_packet_unref(&pkt);
		}
	}
	fprintf(stderr, "pff?\n");
	av_write_trailer(oc); // Writing the end of the file.
	if (!(fmt->flags & AVFMT_NOFILE))
		avio_closep(&oc->pb); // Closing the file.
	avcodec_close(stream->codec);
	// Freeing all the allocated memory:
	sws_freeContext(convertCtx);
	av_frame_free(&rgbpic);
	av_frame_free(&yuvpic);
	avformat_free_context(oc);

	delete currentFile;

	// Cleanup Skia.
	delete surface;
	context = nullptr;

	// Cleanup GLFW.
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}