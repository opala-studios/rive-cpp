#ifndef _RIVE_BLEND_STATE1_DBASE_HPP_
#define _RIVE_BLEND_STATE1_DBASE_HPP_
#include "animation/blend_state.hpp"
#include "core/field_types/core_uint_type.hpp"
namespace rive
{
	class BlendState1DBase : public BlendState
	{
	protected:
		typedef BlendState Super;

	public:
		static const uint16_t typeKey = 76;

		/// Helper to quickly determine if a core object extends another without
		/// RTTI at runtime.
		bool isTypeOf(uint16_t typeKey) const override
		{
			switch (typeKey)
			{
				case BlendState1DBase::typeKey:
				case BlendStateBase::typeKey:
				case LayerStateBase::typeKey:
				case StateMachineLayerComponentBase::typeKey:
					return true;
				default:
					return false;
			}
		}

		uint16_t coreType() const override { return typeKey; }

		static const uint16_t inputIdPropertyKey = 167;

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
			return BlendState::deserialize(propertyKey, reader);
		}

	protected:
		virtual void inputIdChanged() {}
	};
} // namespace rive

#endif