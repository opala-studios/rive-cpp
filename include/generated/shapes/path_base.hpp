#ifndef _RIVE_PATH_BASE_HPP_
#define _RIVE_PATH_BASE_HPP_
#include "core/field_types/core_uint_type.hpp"
#include "node.hpp"
namespace rive
{
	class PathBase : public Node
	{
	protected:
		typedef Node Super;

	public:
		static const uint16_t typeKey = 12;

		/// Helper to quickly determine if a core object extends another without
		/// RTTI at runtime.
		bool isTypeOf(uint16_t typeKey) const override
		{
			switch (typeKey)
			{
				case PathBase::typeKey:
				case NodeBase::typeKey:
				case TransformComponentBase::typeKey:
				case ContainerComponentBase::typeKey:
				case ComponentBase::typeKey:
					return true;
				default:
					return false;
			}
		}

		uint16_t coreType() const override { return typeKey; }

		static const uint16_t pathFlagsPropertyKey = 128;

	private:
		int m_PathFlags = 0;
	public:
		inline int pathFlags() const { return m_PathFlags; }
		void pathFlags(int value)
		{
			if (m_PathFlags == value)
			{
				return;
			}
			m_PathFlags = value;
			pathFlagsChanged();
		}

		void copy(const PathBase& object)
		{
			m_PathFlags = object.m_PathFlags;
			Node::copy(object);
		}

		bool deserialize(uint16_t propertyKey, BinaryReader& reader) override
		{
			switch (propertyKey)
			{
				case pathFlagsPropertyKey:
					m_PathFlags = CoreUintType::deserialize(reader);
					return true;
			}
			return Node::deserialize(propertyKey, reader);
		}

	protected:
		virtual void pathFlagsChanged() {}
	};
} // namespace rive

#endif