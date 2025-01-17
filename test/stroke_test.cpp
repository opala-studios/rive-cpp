#include "catch.hpp"
#include "core/binary_reader.hpp"
#include "file.hpp"
#include "no_op_renderer.hpp"
#include "node.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/shape.hpp"
#include "shapes/paint/stroke.hpp"
#include "shapes/paint/solid_color.hpp"
#include "shapes/paint/color.hpp"
#include <cstdio>

TEST_CASE("stroke can be looked up at runtime", "[file]")
{
	FILE* fp = fopen("../../test/assets/stroke_name_test.riv", "r");
	REQUIRE(fp != nullptr);

	fseek(fp, 0, SEEK_END);
	auto length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	uint8_t* bytes = new uint8_t[length];
	REQUIRE(fread(bytes, 1, length, fp) == length);
	auto reader = rive::BinaryReader(bytes, length);
	rive::File* file = nullptr;
	auto result = rive::File::import(reader, &file);

	REQUIRE(result == rive::ImportResult::success);
	REQUIRE(file != nullptr);
	REQUIRE(file->artboard() != nullptr);

	auto artboard = file->artboard();
	REQUIRE(artboard->find<rive::Stroke>("white_stroke") != nullptr);
	auto stroke = artboard->find<rive::Stroke>("white_stroke");
	REQUIRE(stroke->paint()->is<rive::SolidColor>());
	stroke->paint()->as<rive::SolidColor>()->colorValue(
	    rive::colorARGB(255, 0, 255, 255));

	delete file;
	delete[] bytes;
}