#ifndef _RIVE_CORE_REGISTRY_HPP_
#define _RIVE_CORE_REGISTRY_HPP_
#include "animation/animation.hpp"
#include "animation/animation_state.hpp"
#include "animation/any_state.hpp"
#include "animation/blend_animation.hpp"
#include "animation/blend_animation_1d.hpp"
#include "animation/blend_animation_direct.hpp"
#include "animation/blend_state.hpp"
#include "animation/blend_state_1d.hpp"
#include "animation/blend_state_direct.hpp"
#include "animation/blend_state_transition.hpp"
#include "animation/cubic_interpolator.hpp"
#include "animation/entry_state.hpp"
#include "animation/exit_state.hpp"
#include "animation/keyed_object.hpp"
#include "animation/keyed_property.hpp"
#include "animation/keyframe.hpp"
#include "animation/keyframe_color.hpp"
#include "animation/keyframe_double.hpp"
#include "animation/keyframe_id.hpp"
#include "animation/layer_state.hpp"
#include "animation/linear_animation.hpp"
#include "animation/state_machine.hpp"
#include "animation/state_machine_bool.hpp"
#include "animation/state_machine_component.hpp"
#include "animation/state_machine_input.hpp"
#include "animation/state_machine_layer.hpp"
#include "animation/state_machine_layer_component.hpp"
#include "animation/state_machine_number.hpp"
#include "animation/state_machine_trigger.hpp"
#include "animation/state_transition.hpp"
#include "animation/transition_bool_condition.hpp"
#include "animation/transition_condition.hpp"
#include "animation/transition_number_condition.hpp"
#include "animation/transition_trigger_condition.hpp"
#include "animation/transition_value_condition.hpp"
#include "artboard.hpp"
#include "backboard.hpp"
#include "bones/bone.hpp"
#include "bones/cubic_weight.hpp"
#include "bones/root_bone.hpp"
#include "bones/skeletal_component.hpp"
#include "bones/skin.hpp"
#include "bones/tendon.hpp"
#include "bones/weight.hpp"
#include "component.hpp"
#include "container_component.hpp"
#include "draw_rules.hpp"
#include "draw_target.hpp"
#include "drawable.hpp"
#include "node.hpp"
#include "shapes/clipping_shape.hpp"
#include "shapes/cubic_asymmetric_vertex.hpp"
#include "shapes/cubic_detached_vertex.hpp"
#include "shapes/cubic_mirrored_vertex.hpp"
#include "shapes/cubic_vertex.hpp"
#include "shapes/ellipse.hpp"
#include "shapes/paint/fill.hpp"
#include "shapes/paint/gradient_stop.hpp"
#include "shapes/paint/linear_gradient.hpp"
#include "shapes/paint/radial_gradient.hpp"
#include "shapes/paint/shape_paint.hpp"
#include "shapes/paint/solid_color.hpp"
#include "shapes/paint/stroke.hpp"
#include "shapes/paint/trim_path.hpp"
#include "shapes/parametric_path.hpp"
#include "shapes/path.hpp"
#include "shapes/path_vertex.hpp"
#include "shapes/points_path.hpp"
#include "shapes/polygon.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/shape.hpp"
#include "shapes/star.hpp"
#include "shapes/straight_vertex.hpp"
#include "shapes/triangle.hpp"
#include "transform_component.hpp"
namespace rive
{
	class CoreRegistry
	{
	public:
		static Core* makeCoreInstance(int typeKey)
		{
			switch (typeKey)
			{
				case DrawTargetBase::typeKey:
					return new DrawTarget();
				case AnimationStateBase::typeKey:
					return new AnimationState();
				case KeyedObjectBase::typeKey:
					return new KeyedObject();
				case BlendAnimationDirectBase::typeKey:
					return new BlendAnimationDirect();
				case StateMachineNumberBase::typeKey:
					return new StateMachineNumber();
				case TransitionTriggerConditionBase::typeKey:
					return new TransitionTriggerCondition();
				case KeyedPropertyBase::typeKey:
					return new KeyedProperty();
				case KeyFrameIdBase::typeKey:
					return new KeyFrameId();
				case TransitionNumberConditionBase::typeKey:
					return new TransitionNumberCondition();
				case AnyStateBase::typeKey:
					return new AnyState();
				case StateMachineLayerBase::typeKey:
					return new StateMachineLayer();
				case AnimationBase::typeKey:
					return new Animation();
				case CubicInterpolatorBase::typeKey:
					return new CubicInterpolator();
				case StateTransitionBase::typeKey:
					return new StateTransition();
				case KeyFrameDoubleBase::typeKey:
					return new KeyFrameDouble();
				case KeyFrameColorBase::typeKey:
					return new KeyFrameColor();
				case StateMachineBase::typeKey:
					return new StateMachine();
				case EntryStateBase::typeKey:
					return new EntryState();
				case LinearAnimationBase::typeKey:
					return new LinearAnimation();
				case StateMachineTriggerBase::typeKey:
					return new StateMachineTrigger();
				case BlendStateDirectBase::typeKey:
					return new BlendStateDirect();
				case ExitStateBase::typeKey:
					return new ExitState();
				case BlendState1DBase::typeKey:
					return new BlendState1D();
				case TransitionBoolConditionBase::typeKey:
					return new TransitionBoolCondition();
				case BlendStateTransitionBase::typeKey:
					return new BlendStateTransition();
				case StateMachineBoolBase::typeKey:
					return new StateMachineBool();
				case BlendAnimation1DBase::typeKey:
					return new BlendAnimation1D();
				case LinearGradientBase::typeKey:
					return new LinearGradient();
				case RadialGradientBase::typeKey:
					return new RadialGradient();
				case StrokeBase::typeKey:
					return new Stroke();
				case SolidColorBase::typeKey:
					return new SolidColor();
				case GradientStopBase::typeKey:
					return new GradientStop();
				case TrimPathBase::typeKey:
					return new TrimPath();
				case FillBase::typeKey:
					return new Fill();
				case NodeBase::typeKey:
					return new Node();
				case ShapeBase::typeKey:
					return new Shape();
				case StraightVertexBase::typeKey:
					return new StraightVertex();
				case CubicAsymmetricVertexBase::typeKey:
					return new CubicAsymmetricVertex();
				case PointsPathBase::typeKey:
					return new PointsPath();
				case RectangleBase::typeKey:
					return new Rectangle();
				case CubicMirroredVertexBase::typeKey:
					return new CubicMirroredVertex();
				case TriangleBase::typeKey:
					return new Triangle();
				case EllipseBase::typeKey:
					return new Ellipse();
				case ClippingShapeBase::typeKey:
					return new ClippingShape();
				case PolygonBase::typeKey:
					return new Polygon();
				case StarBase::typeKey:
					return new Star();
				case CubicDetachedVertexBase::typeKey:
					return new CubicDetachedVertex();
				case DrawRulesBase::typeKey:
					return new DrawRules();
				case ArtboardBase::typeKey:
					return new Artboard();
				case BackboardBase::typeKey:
					return new Backboard();
				case WeightBase::typeKey:
					return new Weight();
				case BoneBase::typeKey:
					return new Bone();
				case RootBoneBase::typeKey:
					return new RootBone();
				case SkinBase::typeKey:
					return new Skin();
				case TendonBase::typeKey:
					return new Tendon();
				case CubicWeightBase::typeKey:
					return new CubicWeight();
			}
			return nullptr;
		}
		static void setString(Core* object, int propertyKey, std::string value)
		{
			switch (propertyKey)
			{
				case ComponentBase::namePropertyKey:
					object->as<ComponentBase>()->name(value);
					break;
				case StateMachineComponentBase::namePropertyKey:
					object->as<StateMachineComponentBase>()->name(value);
					break;
				case AnimationBase::namePropertyKey:
					object->as<AnimationBase>()->name(value);
					break;
			}
		}
		static void setUint(Core* object, int propertyKey, int value)
		{
			switch (propertyKey)
			{
				case ComponentBase::parentIdPropertyKey:
					object->as<ComponentBase>()->parentId(value);
					break;
				case DrawTargetBase::drawableIdPropertyKey:
					object->as<DrawTargetBase>()->drawableId(value);
					break;
				case DrawTargetBase::placementValuePropertyKey:
					object->as<DrawTargetBase>()->placementValue(value);
					break;
				case AnimationStateBase::animationIdPropertyKey:
					object->as<AnimationStateBase>()->animationId(value);
					break;
				case KeyedObjectBase::objectIdPropertyKey:
					object->as<KeyedObjectBase>()->objectId(value);
					break;
				case BlendAnimationBase::animationIdPropertyKey:
					object->as<BlendAnimationBase>()->animationId(value);
					break;
				case BlendAnimationDirectBase::inputIdPropertyKey:
					object->as<BlendAnimationDirectBase>()->inputId(value);
					break;
				case TransitionConditionBase::inputIdPropertyKey:
					object->as<TransitionConditionBase>()->inputId(value);
					break;
				case KeyedPropertyBase::propertyKeyPropertyKey:
					object->as<KeyedPropertyBase>()->propertyKey(value);
					break;
				case KeyFrameBase::framePropertyKey:
					object->as<KeyFrameBase>()->frame(value);
					break;
				case KeyFrameBase::interpolationTypePropertyKey:
					object->as<KeyFrameBase>()->interpolationType(value);
					break;
				case KeyFrameBase::interpolatorIdPropertyKey:
					object->as<KeyFrameBase>()->interpolatorId(value);
					break;
				case KeyFrameIdBase::valuePropertyKey:
					object->as<KeyFrameIdBase>()->value(value);
					break;
				case TransitionValueConditionBase::opValuePropertyKey:
					object->as<TransitionValueConditionBase>()->opValue(value);
					break;
				case StateTransitionBase::stateToIdPropertyKey:
					object->as<StateTransitionBase>()->stateToId(value);
					break;
				case StateTransitionBase::flagsPropertyKey:
					object->as<StateTransitionBase>()->flags(value);
					break;
				case StateTransitionBase::durationPropertyKey:
					object->as<StateTransitionBase>()->duration(value);
					break;
				case StateTransitionBase::exitTimePropertyKey:
					object->as<StateTransitionBase>()->exitTime(value);
					break;
				case LinearAnimationBase::fpsPropertyKey:
					object->as<LinearAnimationBase>()->fps(value);
					break;
				case LinearAnimationBase::durationPropertyKey:
					object->as<LinearAnimationBase>()->duration(value);
					break;
				case LinearAnimationBase::loopValuePropertyKey:
					object->as<LinearAnimationBase>()->loopValue(value);
					break;
				case LinearAnimationBase::workStartPropertyKey:
					object->as<LinearAnimationBase>()->workStart(value);
					break;
				case LinearAnimationBase::workEndPropertyKey:
					object->as<LinearAnimationBase>()->workEnd(value);
					break;
				case BlendState1DBase::inputIdPropertyKey:
					object->as<BlendState1DBase>()->inputId(value);
					break;
				case BlendStateTransitionBase::exitBlendAnimationIdPropertyKey:
					object->as<BlendStateTransitionBase>()
					    ->exitBlendAnimationId(value);
					break;
				case StrokeBase::capPropertyKey:
					object->as<StrokeBase>()->cap(value);
					break;
				case StrokeBase::joinPropertyKey:
					object->as<StrokeBase>()->join(value);
					break;
				case TrimPathBase::modeValuePropertyKey:
					object->as<TrimPathBase>()->modeValue(value);
					break;
				case FillBase::fillRulePropertyKey:
					object->as<FillBase>()->fillRule(value);
					break;
				case PathBase::pathFlagsPropertyKey:
					object->as<PathBase>()->pathFlags(value);
					break;
				case DrawableBase::blendModeValuePropertyKey:
					object->as<DrawableBase>()->blendModeValue(value);
					break;
				case DrawableBase::drawableFlagsPropertyKey:
					object->as<DrawableBase>()->drawableFlags(value);
					break;
				case ClippingShapeBase::sourceIdPropertyKey:
					object->as<ClippingShapeBase>()->sourceId(value);
					break;
				case ClippingShapeBase::fillRulePropertyKey:
					object->as<ClippingShapeBase>()->fillRule(value);
					break;
				case PolygonBase::pointsPropertyKey:
					object->as<PolygonBase>()->points(value);
					break;
				case DrawRulesBase::drawTargetIdPropertyKey:
					object->as<DrawRulesBase>()->drawTargetId(value);
					break;
				case WeightBase::valuesPropertyKey:
					object->as<WeightBase>()->values(value);
					break;
				case WeightBase::indicesPropertyKey:
					object->as<WeightBase>()->indices(value);
					break;
				case TendonBase::boneIdPropertyKey:
					object->as<TendonBase>()->boneId(value);
					break;
				case CubicWeightBase::inValuesPropertyKey:
					object->as<CubicWeightBase>()->inValues(value);
					break;
				case CubicWeightBase::inIndicesPropertyKey:
					object->as<CubicWeightBase>()->inIndices(value);
					break;
				case CubicWeightBase::outValuesPropertyKey:
					object->as<CubicWeightBase>()->outValues(value);
					break;
				case CubicWeightBase::outIndicesPropertyKey:
					object->as<CubicWeightBase>()->outIndices(value);
					break;
			}
		}
		static void setDouble(Core* object, int propertyKey, float value)
		{
			switch (propertyKey)
			{
				case StateMachineNumberBase::valuePropertyKey:
					object->as<StateMachineNumberBase>()->value(value);
					break;
				case TransitionNumberConditionBase::valuePropertyKey:
					object->as<TransitionNumberConditionBase>()->value(value);
					break;
				case CubicInterpolatorBase::x1PropertyKey:
					object->as<CubicInterpolatorBase>()->x1(value);
					break;
				case CubicInterpolatorBase::y1PropertyKey:
					object->as<CubicInterpolatorBase>()->y1(value);
					break;
				case CubicInterpolatorBase::x2PropertyKey:
					object->as<CubicInterpolatorBase>()->x2(value);
					break;
				case CubicInterpolatorBase::y2PropertyKey:
					object->as<CubicInterpolatorBase>()->y2(value);
					break;
				case KeyFrameDoubleBase::valuePropertyKey:
					object->as<KeyFrameDoubleBase>()->value(value);
					break;
				case LinearAnimationBase::speedPropertyKey:
					object->as<LinearAnimationBase>()->speed(value);
					break;
				case BlendAnimation1DBase::valuePropertyKey:
					object->as<BlendAnimation1DBase>()->value(value);
					break;
				case LinearGradientBase::startXPropertyKey:
					object->as<LinearGradientBase>()->startX(value);
					break;
				case LinearGradientBase::startYPropertyKey:
					object->as<LinearGradientBase>()->startY(value);
					break;
				case LinearGradientBase::endXPropertyKey:
					object->as<LinearGradientBase>()->endX(value);
					break;
				case LinearGradientBase::endYPropertyKey:
					object->as<LinearGradientBase>()->endY(value);
					break;
				case LinearGradientBase::opacityPropertyKey:
					object->as<LinearGradientBase>()->opacity(value);
					break;
				case StrokeBase::thicknessPropertyKey:
					object->as<StrokeBase>()->thickness(value);
					break;
				case GradientStopBase::positionPropertyKey:
					object->as<GradientStopBase>()->position(value);
					break;
				case TrimPathBase::startPropertyKey:
					object->as<TrimPathBase>()->start(value);
					break;
				case TrimPathBase::endPropertyKey:
					object->as<TrimPathBase>()->end(value);
					break;
				case TrimPathBase::offsetPropertyKey:
					object->as<TrimPathBase>()->offset(value);
					break;
				case TransformComponentBase::rotationPropertyKey:
					object->as<TransformComponentBase>()->rotation(value);
					break;
				case TransformComponentBase::scaleXPropertyKey:
					object->as<TransformComponentBase>()->scaleX(value);
					break;
				case TransformComponentBase::scaleYPropertyKey:
					object->as<TransformComponentBase>()->scaleY(value);
					break;
				case TransformComponentBase::opacityPropertyKey:
					object->as<TransformComponentBase>()->opacity(value);
					break;
				case NodeBase::xPropertyKey:
					object->as<NodeBase>()->x(value);
					break;
				case NodeBase::yPropertyKey:
					object->as<NodeBase>()->y(value);
					break;
				case PathVertexBase::xPropertyKey:
					object->as<PathVertexBase>()->x(value);
					break;
				case PathVertexBase::yPropertyKey:
					object->as<PathVertexBase>()->y(value);
					break;
				case StraightVertexBase::radiusPropertyKey:
					object->as<StraightVertexBase>()->radius(value);
					break;
				case CubicAsymmetricVertexBase::rotationPropertyKey:
					object->as<CubicAsymmetricVertexBase>()->rotation(value);
					break;
				case CubicAsymmetricVertexBase::inDistancePropertyKey:
					object->as<CubicAsymmetricVertexBase>()->inDistance(value);
					break;
				case CubicAsymmetricVertexBase::outDistancePropertyKey:
					object->as<CubicAsymmetricVertexBase>()->outDistance(value);
					break;
				case ParametricPathBase::widthPropertyKey:
					object->as<ParametricPathBase>()->width(value);
					break;
				case ParametricPathBase::heightPropertyKey:
					object->as<ParametricPathBase>()->height(value);
					break;
				case ParametricPathBase::originXPropertyKey:
					object->as<ParametricPathBase>()->originX(value);
					break;
				case ParametricPathBase::originYPropertyKey:
					object->as<ParametricPathBase>()->originY(value);
					break;
				case RectangleBase::cornerRadiusTLPropertyKey:
					object->as<RectangleBase>()->cornerRadiusTL(value);
					break;
				case RectangleBase::cornerRadiusTRPropertyKey:
					object->as<RectangleBase>()->cornerRadiusTR(value);
					break;
				case RectangleBase::cornerRadiusBLPropertyKey:
					object->as<RectangleBase>()->cornerRadiusBL(value);
					break;
				case RectangleBase::cornerRadiusBRPropertyKey:
					object->as<RectangleBase>()->cornerRadiusBR(value);
					break;
				case CubicMirroredVertexBase::rotationPropertyKey:
					object->as<CubicMirroredVertexBase>()->rotation(value);
					break;
				case CubicMirroredVertexBase::distancePropertyKey:
					object->as<CubicMirroredVertexBase>()->distance(value);
					break;
				case PolygonBase::cornerRadiusPropertyKey:
					object->as<PolygonBase>()->cornerRadius(value);
					break;
				case StarBase::innerRadiusPropertyKey:
					object->as<StarBase>()->innerRadius(value);
					break;
				case CubicDetachedVertexBase::inRotationPropertyKey:
					object->as<CubicDetachedVertexBase>()->inRotation(value);
					break;
				case CubicDetachedVertexBase::inDistancePropertyKey:
					object->as<CubicDetachedVertexBase>()->inDistance(value);
					break;
				case CubicDetachedVertexBase::outRotationPropertyKey:
					object->as<CubicDetachedVertexBase>()->outRotation(value);
					break;
				case CubicDetachedVertexBase::outDistancePropertyKey:
					object->as<CubicDetachedVertexBase>()->outDistance(value);
					break;
				case ArtboardBase::widthPropertyKey:
					object->as<ArtboardBase>()->width(value);
					break;
				case ArtboardBase::heightPropertyKey:
					object->as<ArtboardBase>()->height(value);
					break;
				case ArtboardBase::xPropertyKey:
					object->as<ArtboardBase>()->x(value);
					break;
				case ArtboardBase::yPropertyKey:
					object->as<ArtboardBase>()->y(value);
					break;
				case ArtboardBase::originXPropertyKey:
					object->as<ArtboardBase>()->originX(value);
					break;
				case ArtboardBase::originYPropertyKey:
					object->as<ArtboardBase>()->originY(value);
					break;
				case BoneBase::lengthPropertyKey:
					object->as<BoneBase>()->length(value);
					break;
				case RootBoneBase::xPropertyKey:
					object->as<RootBoneBase>()->x(value);
					break;
				case RootBoneBase::yPropertyKey:
					object->as<RootBoneBase>()->y(value);
					break;
				case SkinBase::xxPropertyKey:
					object->as<SkinBase>()->xx(value);
					break;
				case SkinBase::yxPropertyKey:
					object->as<SkinBase>()->yx(value);
					break;
				case SkinBase::xyPropertyKey:
					object->as<SkinBase>()->xy(value);
					break;
				case SkinBase::yyPropertyKey:
					object->as<SkinBase>()->yy(value);
					break;
				case SkinBase::txPropertyKey:
					object->as<SkinBase>()->tx(value);
					break;
				case SkinBase::tyPropertyKey:
					object->as<SkinBase>()->ty(value);
					break;
				case TendonBase::xxPropertyKey:
					object->as<TendonBase>()->xx(value);
					break;
				case TendonBase::yxPropertyKey:
					object->as<TendonBase>()->yx(value);
					break;
				case TendonBase::xyPropertyKey:
					object->as<TendonBase>()->xy(value);
					break;
				case TendonBase::yyPropertyKey:
					object->as<TendonBase>()->yy(value);
					break;
				case TendonBase::txPropertyKey:
					object->as<TendonBase>()->tx(value);
					break;
				case TendonBase::tyPropertyKey:
					object->as<TendonBase>()->ty(value);
					break;
			}
		}
		static void setColor(Core* object, int propertyKey, int value)
		{
			switch (propertyKey)
			{
				case KeyFrameColorBase::valuePropertyKey:
					object->as<KeyFrameColorBase>()->value(value);
					break;
				case SolidColorBase::colorValuePropertyKey:
					object->as<SolidColorBase>()->colorValue(value);
					break;
				case GradientStopBase::colorValuePropertyKey:
					object->as<GradientStopBase>()->colorValue(value);
					break;
			}
		}
		static void setBool(Core* object, int propertyKey, bool value)
		{
			switch (propertyKey)
			{
				case LinearAnimationBase::enableWorkAreaPropertyKey:
					object->as<LinearAnimationBase>()->enableWorkArea(value);
					break;
				case StateMachineBoolBase::valuePropertyKey:
					object->as<StateMachineBoolBase>()->value(value);
					break;
				case ShapePaintBase::isVisiblePropertyKey:
					object->as<ShapePaintBase>()->isVisible(value);
					break;
				case StrokeBase::transformAffectsStrokePropertyKey:
					object->as<StrokeBase>()->transformAffectsStroke(value);
					break;
				case PointsPathBase::isClosedPropertyKey:
					object->as<PointsPathBase>()->isClosed(value);
					break;
				case RectangleBase::linkCornerRadiusPropertyKey:
					object->as<RectangleBase>()->linkCornerRadius(value);
					break;
				case ClippingShapeBase::isVisiblePropertyKey:
					object->as<ClippingShapeBase>()->isVisible(value);
					break;
			}
		}
		static std::string getString(Core* object, int propertyKey)
		{
			switch (propertyKey)
			{
				case ComponentBase::namePropertyKey:
					return object->as<ComponentBase>()->name();
				case StateMachineComponentBase::namePropertyKey:
					return object->as<StateMachineComponentBase>()->name();
				case AnimationBase::namePropertyKey:
					return object->as<AnimationBase>()->name();
			}
			return "";
		}
		static int getUint(Core* object, int propertyKey)
		{
			switch (propertyKey)
			{
				case ComponentBase::parentIdPropertyKey:
					return object->as<ComponentBase>()->parentId();
				case DrawTargetBase::drawableIdPropertyKey:
					return object->as<DrawTargetBase>()->drawableId();
				case DrawTargetBase::placementValuePropertyKey:
					return object->as<DrawTargetBase>()->placementValue();
				case AnimationStateBase::animationIdPropertyKey:
					return object->as<AnimationStateBase>()->animationId();
				case KeyedObjectBase::objectIdPropertyKey:
					return object->as<KeyedObjectBase>()->objectId();
				case BlendAnimationBase::animationIdPropertyKey:
					return object->as<BlendAnimationBase>()->animationId();
				case BlendAnimationDirectBase::inputIdPropertyKey:
					return object->as<BlendAnimationDirectBase>()->inputId();
				case TransitionConditionBase::inputIdPropertyKey:
					return object->as<TransitionConditionBase>()->inputId();
				case KeyedPropertyBase::propertyKeyPropertyKey:
					return object->as<KeyedPropertyBase>()->propertyKey();
				case KeyFrameBase::framePropertyKey:
					return object->as<KeyFrameBase>()->frame();
				case KeyFrameBase::interpolationTypePropertyKey:
					return object->as<KeyFrameBase>()->interpolationType();
				case KeyFrameBase::interpolatorIdPropertyKey:
					return object->as<KeyFrameBase>()->interpolatorId();
				case KeyFrameIdBase::valuePropertyKey:
					return object->as<KeyFrameIdBase>()->value();
				case TransitionValueConditionBase::opValuePropertyKey:
					return object->as<TransitionValueConditionBase>()
					    ->opValue();
				case StateTransitionBase::stateToIdPropertyKey:
					return object->as<StateTransitionBase>()->stateToId();
				case StateTransitionBase::flagsPropertyKey:
					return object->as<StateTransitionBase>()->flags();
				case StateTransitionBase::durationPropertyKey:
					return object->as<StateTransitionBase>()->duration();
				case StateTransitionBase::exitTimePropertyKey:
					return object->as<StateTransitionBase>()->exitTime();
				case LinearAnimationBase::fpsPropertyKey:
					return object->as<LinearAnimationBase>()->fps();
				case LinearAnimationBase::durationPropertyKey:
					return object->as<LinearAnimationBase>()->duration();
				case LinearAnimationBase::loopValuePropertyKey:
					return object->as<LinearAnimationBase>()->loopValue();
				case LinearAnimationBase::workStartPropertyKey:
					return object->as<LinearAnimationBase>()->workStart();
				case LinearAnimationBase::workEndPropertyKey:
					return object->as<LinearAnimationBase>()->workEnd();
				case BlendState1DBase::inputIdPropertyKey:
					return object->as<BlendState1DBase>()->inputId();
				case BlendStateTransitionBase::exitBlendAnimationIdPropertyKey:
					return object->as<BlendStateTransitionBase>()
					    ->exitBlendAnimationId();
				case StrokeBase::capPropertyKey:
					return object->as<StrokeBase>()->cap();
				case StrokeBase::joinPropertyKey:
					return object->as<StrokeBase>()->join();
				case TrimPathBase::modeValuePropertyKey:
					return object->as<TrimPathBase>()->modeValue();
				case FillBase::fillRulePropertyKey:
					return object->as<FillBase>()->fillRule();
				case PathBase::pathFlagsPropertyKey:
					return object->as<PathBase>()->pathFlags();
				case DrawableBase::blendModeValuePropertyKey:
					return object->as<DrawableBase>()->blendModeValue();
				case DrawableBase::drawableFlagsPropertyKey:
					return object->as<DrawableBase>()->drawableFlags();
				case ClippingShapeBase::sourceIdPropertyKey:
					return object->as<ClippingShapeBase>()->sourceId();
				case ClippingShapeBase::fillRulePropertyKey:
					return object->as<ClippingShapeBase>()->fillRule();
				case PolygonBase::pointsPropertyKey:
					return object->as<PolygonBase>()->points();
				case DrawRulesBase::drawTargetIdPropertyKey:
					return object->as<DrawRulesBase>()->drawTargetId();
				case WeightBase::valuesPropertyKey:
					return object->as<WeightBase>()->values();
				case WeightBase::indicesPropertyKey:
					return object->as<WeightBase>()->indices();
				case TendonBase::boneIdPropertyKey:
					return object->as<TendonBase>()->boneId();
				case CubicWeightBase::inValuesPropertyKey:
					return object->as<CubicWeightBase>()->inValues();
				case CubicWeightBase::inIndicesPropertyKey:
					return object->as<CubicWeightBase>()->inIndices();
				case CubicWeightBase::outValuesPropertyKey:
					return object->as<CubicWeightBase>()->outValues();
				case CubicWeightBase::outIndicesPropertyKey:
					return object->as<CubicWeightBase>()->outIndices();
			}
			return 0;
		}
		static float getDouble(Core* object, int propertyKey)
		{
			switch (propertyKey)
			{
				case StateMachineNumberBase::valuePropertyKey:
					return object->as<StateMachineNumberBase>()->value();
				case TransitionNumberConditionBase::valuePropertyKey:
					return object->as<TransitionNumberConditionBase>()->value();
				case CubicInterpolatorBase::x1PropertyKey:
					return object->as<CubicInterpolatorBase>()->x1();
				case CubicInterpolatorBase::y1PropertyKey:
					return object->as<CubicInterpolatorBase>()->y1();
				case CubicInterpolatorBase::x2PropertyKey:
					return object->as<CubicInterpolatorBase>()->x2();
				case CubicInterpolatorBase::y2PropertyKey:
					return object->as<CubicInterpolatorBase>()->y2();
				case KeyFrameDoubleBase::valuePropertyKey:
					return object->as<KeyFrameDoubleBase>()->value();
				case LinearAnimationBase::speedPropertyKey:
					return object->as<LinearAnimationBase>()->speed();
				case BlendAnimation1DBase::valuePropertyKey:
					return object->as<BlendAnimation1DBase>()->value();
				case LinearGradientBase::startXPropertyKey:
					return object->as<LinearGradientBase>()->startX();
				case LinearGradientBase::startYPropertyKey:
					return object->as<LinearGradientBase>()->startY();
				case LinearGradientBase::endXPropertyKey:
					return object->as<LinearGradientBase>()->endX();
				case LinearGradientBase::endYPropertyKey:
					return object->as<LinearGradientBase>()->endY();
				case LinearGradientBase::opacityPropertyKey:
					return object->as<LinearGradientBase>()->opacity();
				case StrokeBase::thicknessPropertyKey:
					return object->as<StrokeBase>()->thickness();
				case GradientStopBase::positionPropertyKey:
					return object->as<GradientStopBase>()->position();
				case TrimPathBase::startPropertyKey:
					return object->as<TrimPathBase>()->start();
				case TrimPathBase::endPropertyKey:
					return object->as<TrimPathBase>()->end();
				case TrimPathBase::offsetPropertyKey:
					return object->as<TrimPathBase>()->offset();
				case TransformComponentBase::rotationPropertyKey:
					return object->as<TransformComponentBase>()->rotation();
				case TransformComponentBase::scaleXPropertyKey:
					return object->as<TransformComponentBase>()->scaleX();
				case TransformComponentBase::scaleYPropertyKey:
					return object->as<TransformComponentBase>()->scaleY();
				case TransformComponentBase::opacityPropertyKey:
					return object->as<TransformComponentBase>()->opacity();
				case NodeBase::xPropertyKey:
					return object->as<NodeBase>()->x();
				case NodeBase::yPropertyKey:
					return object->as<NodeBase>()->y();
				case PathVertexBase::xPropertyKey:
					return object->as<PathVertexBase>()->x();
				case PathVertexBase::yPropertyKey:
					return object->as<PathVertexBase>()->y();
				case StraightVertexBase::radiusPropertyKey:
					return object->as<StraightVertexBase>()->radius();
				case CubicAsymmetricVertexBase::rotationPropertyKey:
					return object->as<CubicAsymmetricVertexBase>()->rotation();
				case CubicAsymmetricVertexBase::inDistancePropertyKey:
					return object->as<CubicAsymmetricVertexBase>()
					    ->inDistance();
				case CubicAsymmetricVertexBase::outDistancePropertyKey:
					return object->as<CubicAsymmetricVertexBase>()
					    ->outDistance();
				case ParametricPathBase::widthPropertyKey:
					return object->as<ParametricPathBase>()->width();
				case ParametricPathBase::heightPropertyKey:
					return object->as<ParametricPathBase>()->height();
				case ParametricPathBase::originXPropertyKey:
					return object->as<ParametricPathBase>()->originX();
				case ParametricPathBase::originYPropertyKey:
					return object->as<ParametricPathBase>()->originY();
				case RectangleBase::cornerRadiusTLPropertyKey:
					return object->as<RectangleBase>()->cornerRadiusTL();
				case RectangleBase::cornerRadiusTRPropertyKey:
					return object->as<RectangleBase>()->cornerRadiusTR();
				case RectangleBase::cornerRadiusBLPropertyKey:
					return object->as<RectangleBase>()->cornerRadiusBL();
				case RectangleBase::cornerRadiusBRPropertyKey:
					return object->as<RectangleBase>()->cornerRadiusBR();
				case CubicMirroredVertexBase::rotationPropertyKey:
					return object->as<CubicMirroredVertexBase>()->rotation();
				case CubicMirroredVertexBase::distancePropertyKey:
					return object->as<CubicMirroredVertexBase>()->distance();
				case PolygonBase::cornerRadiusPropertyKey:
					return object->as<PolygonBase>()->cornerRadius();
				case StarBase::innerRadiusPropertyKey:
					return object->as<StarBase>()->innerRadius();
				case CubicDetachedVertexBase::inRotationPropertyKey:
					return object->as<CubicDetachedVertexBase>()->inRotation();
				case CubicDetachedVertexBase::inDistancePropertyKey:
					return object->as<CubicDetachedVertexBase>()->inDistance();
				case CubicDetachedVertexBase::outRotationPropertyKey:
					return object->as<CubicDetachedVertexBase>()->outRotation();
				case CubicDetachedVertexBase::outDistancePropertyKey:
					return object->as<CubicDetachedVertexBase>()->outDistance();
				case ArtboardBase::widthPropertyKey:
					return object->as<ArtboardBase>()->width();
				case ArtboardBase::heightPropertyKey:
					return object->as<ArtboardBase>()->height();
				case ArtboardBase::xPropertyKey:
					return object->as<ArtboardBase>()->x();
				case ArtboardBase::yPropertyKey:
					return object->as<ArtboardBase>()->y();
				case ArtboardBase::originXPropertyKey:
					return object->as<ArtboardBase>()->originX();
				case ArtboardBase::originYPropertyKey:
					return object->as<ArtboardBase>()->originY();
				case BoneBase::lengthPropertyKey:
					return object->as<BoneBase>()->length();
				case RootBoneBase::xPropertyKey:
					return object->as<RootBoneBase>()->x();
				case RootBoneBase::yPropertyKey:
					return object->as<RootBoneBase>()->y();
				case SkinBase::xxPropertyKey:
					return object->as<SkinBase>()->xx();
				case SkinBase::yxPropertyKey:
					return object->as<SkinBase>()->yx();
				case SkinBase::xyPropertyKey:
					return object->as<SkinBase>()->xy();
				case SkinBase::yyPropertyKey:
					return object->as<SkinBase>()->yy();
				case SkinBase::txPropertyKey:
					return object->as<SkinBase>()->tx();
				case SkinBase::tyPropertyKey:
					return object->as<SkinBase>()->ty();
				case TendonBase::xxPropertyKey:
					return object->as<TendonBase>()->xx();
				case TendonBase::yxPropertyKey:
					return object->as<TendonBase>()->yx();
				case TendonBase::xyPropertyKey:
					return object->as<TendonBase>()->xy();
				case TendonBase::yyPropertyKey:
					return object->as<TendonBase>()->yy();
				case TendonBase::txPropertyKey:
					return object->as<TendonBase>()->tx();
				case TendonBase::tyPropertyKey:
					return object->as<TendonBase>()->ty();
			}
			return 0.0f;
		}
		static int getColor(Core* object, int propertyKey)
		{
			switch (propertyKey)
			{
				case KeyFrameColorBase::valuePropertyKey:
					return object->as<KeyFrameColorBase>()->value();
				case SolidColorBase::colorValuePropertyKey:
					return object->as<SolidColorBase>()->colorValue();
				case GradientStopBase::colorValuePropertyKey:
					return object->as<GradientStopBase>()->colorValue();
			}
			return 0;
		}
		static bool getBool(Core* object, int propertyKey)
		{
			switch (propertyKey)
			{
				case LinearAnimationBase::enableWorkAreaPropertyKey:
					return object->as<LinearAnimationBase>()->enableWorkArea();
				case StateMachineBoolBase::valuePropertyKey:
					return object->as<StateMachineBoolBase>()->value();
				case ShapePaintBase::isVisiblePropertyKey:
					return object->as<ShapePaintBase>()->isVisible();
				case StrokeBase::transformAffectsStrokePropertyKey:
					return object->as<StrokeBase>()->transformAffectsStroke();
				case PointsPathBase::isClosedPropertyKey:
					return object->as<PointsPathBase>()->isClosed();
				case RectangleBase::linkCornerRadiusPropertyKey:
					return object->as<RectangleBase>()->linkCornerRadius();
				case ClippingShapeBase::isVisiblePropertyKey:
					return object->as<ClippingShapeBase>()->isVisible();
			}
			return false;
		}
		static int propertyFieldId(int propertyKey)
		{
			switch (propertyKey)
			{
				case ComponentBase::namePropertyKey:
				case StateMachineComponentBase::namePropertyKey:
				case AnimationBase::namePropertyKey:
					return CoreStringType::id;
				case ComponentBase::parentIdPropertyKey:
				case DrawTargetBase::drawableIdPropertyKey:
				case DrawTargetBase::placementValuePropertyKey:
				case AnimationStateBase::animationIdPropertyKey:
				case KeyedObjectBase::objectIdPropertyKey:
				case BlendAnimationBase::animationIdPropertyKey:
				case BlendAnimationDirectBase::inputIdPropertyKey:
				case TransitionConditionBase::inputIdPropertyKey:
				case KeyedPropertyBase::propertyKeyPropertyKey:
				case KeyFrameBase::framePropertyKey:
				case KeyFrameBase::interpolationTypePropertyKey:
				case KeyFrameBase::interpolatorIdPropertyKey:
				case KeyFrameIdBase::valuePropertyKey:
				case TransitionValueConditionBase::opValuePropertyKey:
				case StateTransitionBase::stateToIdPropertyKey:
				case StateTransitionBase::flagsPropertyKey:
				case StateTransitionBase::durationPropertyKey:
				case StateTransitionBase::exitTimePropertyKey:
				case LinearAnimationBase::fpsPropertyKey:
				case LinearAnimationBase::durationPropertyKey:
				case LinearAnimationBase::loopValuePropertyKey:
				case LinearAnimationBase::workStartPropertyKey:
				case LinearAnimationBase::workEndPropertyKey:
				case BlendState1DBase::inputIdPropertyKey:
				case BlendStateTransitionBase::exitBlendAnimationIdPropertyKey:
				case StrokeBase::capPropertyKey:
				case StrokeBase::joinPropertyKey:
				case TrimPathBase::modeValuePropertyKey:
				case FillBase::fillRulePropertyKey:
				case PathBase::pathFlagsPropertyKey:
				case DrawableBase::blendModeValuePropertyKey:
				case DrawableBase::drawableFlagsPropertyKey:
				case ClippingShapeBase::sourceIdPropertyKey:
				case ClippingShapeBase::fillRulePropertyKey:
				case PolygonBase::pointsPropertyKey:
				case DrawRulesBase::drawTargetIdPropertyKey:
				case WeightBase::valuesPropertyKey:
				case WeightBase::indicesPropertyKey:
				case TendonBase::boneIdPropertyKey:
				case CubicWeightBase::inValuesPropertyKey:
				case CubicWeightBase::inIndicesPropertyKey:
				case CubicWeightBase::outValuesPropertyKey:
				case CubicWeightBase::outIndicesPropertyKey:
					return CoreUintType::id;
				case StateMachineNumberBase::valuePropertyKey:
				case TransitionNumberConditionBase::valuePropertyKey:
				case CubicInterpolatorBase::x1PropertyKey:
				case CubicInterpolatorBase::y1PropertyKey:
				case CubicInterpolatorBase::x2PropertyKey:
				case CubicInterpolatorBase::y2PropertyKey:
				case KeyFrameDoubleBase::valuePropertyKey:
				case LinearAnimationBase::speedPropertyKey:
				case BlendAnimation1DBase::valuePropertyKey:
				case LinearGradientBase::startXPropertyKey:
				case LinearGradientBase::startYPropertyKey:
				case LinearGradientBase::endXPropertyKey:
				case LinearGradientBase::endYPropertyKey:
				case LinearGradientBase::opacityPropertyKey:
				case StrokeBase::thicknessPropertyKey:
				case GradientStopBase::positionPropertyKey:
				case TrimPathBase::startPropertyKey:
				case TrimPathBase::endPropertyKey:
				case TrimPathBase::offsetPropertyKey:
				case TransformComponentBase::rotationPropertyKey:
				case TransformComponentBase::scaleXPropertyKey:
				case TransformComponentBase::scaleYPropertyKey:
				case TransformComponentBase::opacityPropertyKey:
				case NodeBase::xPropertyKey:
				case NodeBase::yPropertyKey:
				case PathVertexBase::xPropertyKey:
				case PathVertexBase::yPropertyKey:
				case StraightVertexBase::radiusPropertyKey:
				case CubicAsymmetricVertexBase::rotationPropertyKey:
				case CubicAsymmetricVertexBase::inDistancePropertyKey:
				case CubicAsymmetricVertexBase::outDistancePropertyKey:
				case ParametricPathBase::widthPropertyKey:
				case ParametricPathBase::heightPropertyKey:
				case ParametricPathBase::originXPropertyKey:
				case ParametricPathBase::originYPropertyKey:
				case RectangleBase::cornerRadiusTLPropertyKey:
				case RectangleBase::cornerRadiusTRPropertyKey:
				case RectangleBase::cornerRadiusBLPropertyKey:
				case RectangleBase::cornerRadiusBRPropertyKey:
				case CubicMirroredVertexBase::rotationPropertyKey:
				case CubicMirroredVertexBase::distancePropertyKey:
				case PolygonBase::cornerRadiusPropertyKey:
				case StarBase::innerRadiusPropertyKey:
				case CubicDetachedVertexBase::inRotationPropertyKey:
				case CubicDetachedVertexBase::inDistancePropertyKey:
				case CubicDetachedVertexBase::outRotationPropertyKey:
				case CubicDetachedVertexBase::outDistancePropertyKey:
				case ArtboardBase::widthPropertyKey:
				case ArtboardBase::heightPropertyKey:
				case ArtboardBase::xPropertyKey:
				case ArtboardBase::yPropertyKey:
				case ArtboardBase::originXPropertyKey:
				case ArtboardBase::originYPropertyKey:
				case BoneBase::lengthPropertyKey:
				case RootBoneBase::xPropertyKey:
				case RootBoneBase::yPropertyKey:
				case SkinBase::xxPropertyKey:
				case SkinBase::yxPropertyKey:
				case SkinBase::xyPropertyKey:
				case SkinBase::yyPropertyKey:
				case SkinBase::txPropertyKey:
				case SkinBase::tyPropertyKey:
				case TendonBase::xxPropertyKey:
				case TendonBase::yxPropertyKey:
				case TendonBase::xyPropertyKey:
				case TendonBase::yyPropertyKey:
				case TendonBase::txPropertyKey:
				case TendonBase::tyPropertyKey:
					return CoreDoubleType::id;
				case KeyFrameColorBase::valuePropertyKey:
				case SolidColorBase::colorValuePropertyKey:
				case GradientStopBase::colorValuePropertyKey:
					return CoreColorType::id;
				case LinearAnimationBase::enableWorkAreaPropertyKey:
				case StateMachineBoolBase::valuePropertyKey:
				case ShapePaintBase::isVisiblePropertyKey:
				case StrokeBase::transformAffectsStrokePropertyKey:
				case PointsPathBase::isClosedPropertyKey:
				case RectangleBase::linkCornerRadiusPropertyKey:
				case ClippingShapeBase::isVisiblePropertyKey:
					return CoreBoolType::id;
				default:
					return -1;
			}
		}
	};
} // namespace rive

#endif