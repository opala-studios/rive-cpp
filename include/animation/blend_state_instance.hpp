#ifndef _RIVE_BLEND_STATE_INSTANCE_HPP_
#define _RIVE_BLEND_STATE_INSTANCE_HPP_

#include <string>
#include <vector>
#include "animation/state_instance.hpp"
#include "animation/blend_state.hpp"
#include "animation/linear_animation_instance.hpp"

namespace rive
{
	class AnimationState;

	template <class K, class T> class BlendStateInstance;
	template <class T> class BlendStateAnimationInstance
	{
		template <class A, class B> friend class BlendStateInstance;

	private:
		const T* m_BlendAnimation;
		LinearAnimationInstance m_AnimationInstance;
		float m_Mix = 0.0f;

	public:
		const T* blendAnimation() const { return m_BlendAnimation; }
		const LinearAnimationInstance* animationInstance() const
		{
			return &m_AnimationInstance;
		}

		BlendStateAnimationInstance(const T* blendAnimation) :
		    m_BlendAnimation(blendAnimation),
		    m_AnimationInstance(blendAnimation->animation())
		{
		}

		void mix(float value) { m_Mix = value; }
	};

	template <class K, class T> class BlendStateInstance : public StateInstance
	{
	protected:
		std::vector<BlendStateAnimationInstance<T>> m_AnimationInstances;
		bool m_KeepGoing = true;

	public:
		BlendStateInstance(const K* blendState) : StateInstance(blendState)
		{
			for (auto blendAnimation : blendState->animations())
			{
				m_AnimationInstances.emplace_back(
				    BlendStateAnimationInstance<T>(
				        static_cast<T*>(blendAnimation)));
			}
		}

		bool keepGoing() const override { return m_KeepGoing; }

		void advance(float seconds, SMIInput** inputs) override
		{
			m_KeepGoing = false;
			for (auto& animation : m_AnimationInstances)
			{
				if (animation.m_AnimationInstance.advance(seconds))
				{
					m_KeepGoing = true;
				}
			}
		}

		void apply(Artboard* artboard, float mix) override
		{
			for (auto& animation : m_AnimationInstances)
			{
				float m = mix * animation.m_Mix;
				animation.m_AnimationInstance.apply(artboard, m);
			}
		}

		// Find the animationInstance that corresponds to the blendAnimation.
		const LinearAnimationInstance*
		animationInstance(const BlendAnimation* blendAnimation) const
		{
			for (auto& animation : m_AnimationInstances)
			{
				if (animation.m_BlendAnimation == blendAnimation)
				{
					return animation.animationInstance();
				}
			}
			return nullptr;
		}
	};
} // namespace rive
#endif