#ifndef _RIVE_BLEND_ANIMATION_DIRECT_BASE_HPP_
#define _RIVE_BLEND_ANIMATION_DIRECT_BASE_HPP_
#include "animation/blend_animation.hpp"
#include "core/field_types/core_uint_type.hpp"
namespace rive
{
	class BlendAnimationDirectBase : public BlendAnimation
	{
	protected:
		typedef BlendAnimation Super;

	public:
		static const uint16_t typeKey = 77;

		/// Helper to quickly determine if a core object extends another without
		/// RTTI at runtime.
		bool isTypeOf(uint16_t typeKey) const override
		{
			switch (typeKey)
			{
				case BlendAnimationDirectBase::typeKey:
				case BlendAnimationBase::typeKey:
					return true;
				default:
					return false;
			}
		}

		uint16_t coreType() const override { return typeKey; }

		static const uint16_t inputIdPropertyKey = 168;

	private:
		int m_InputId = -1;
	public:
		inline int inputId() const { return m_InputId; }
		void inputId(int value)
		{
			if (m_InputId == value)
			{
				return;
			}
			m_InputId = value;
			inputIdChanged();
		}

		bool deserialize(uint16_t propertyKey, BinaryReader& reader) override
		{
			switch (propertyKey)
			{
				case inputIdPropertyKey:
					m_InputId = CoreUintType::deserialize(reader);
					return true;
			}
			return BlendAnimation::deserialize(propertyKey, reader);
		}

	protected:
		virtual void inputIdChanged() {}
	};
} // namespace rive

#endif