#ifndef _RIVE_ANIMATION_STATE_INSTANCE_HPP_
#define _RIVE_ANIMATION_STATE_INSTANCE_HPP_

#include <string>
#include "animation/state_instance.hpp"
#include "animation/linear_animation_instance.hpp"

namespace rive
{
	class AnimationState;

	/// Represents an instance of an animation state.
	class AnimationStateInstance : public StateInstance
	{
	private:
		LinearAnimationInstance m_AnimationInstance;
		bool m_KeepGoing;

	public:
		AnimationStateInstance(const AnimationState* animationState);

		void advance(float seconds, SMIInput** inputs) override;
		void apply(Artboard* artboard, float mix) override;

		bool keepGoing() const override;

		const LinearAnimationInstance* animationInstance() const
		{
			return &m_AnimationInstance;
		}

		LinearAnimationInstance* animationInstance()
		{
			return &m_AnimationInstance;
		}
	};
} // namespace rive
#endif