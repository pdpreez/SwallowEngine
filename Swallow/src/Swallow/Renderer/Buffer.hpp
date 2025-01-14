#pragma once

namespace Swallow {

	enum class ShaderDataType : uint8_t
	{
		NONE, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
	};

	struct BufferElement
	{
		std::string Name;
		ShaderDataType Type;
		uint32_t Size;
		uint32_t Offset;
		bool Normalized;

		BufferElement(ShaderDataType type, const std::string &name, bool normalized = false);		


		inline uint32_t GetComponentCount() const {
			switch (Type)
			{
				case Swallow::ShaderDataType::Float: return 1;
				case Swallow::ShaderDataType::Float2: return 2;
				case Swallow::ShaderDataType::Float3: return 3;
				case Swallow::ShaderDataType::Float4: return 4;
				case Swallow::ShaderDataType::Mat3: return 3 * 3;
				case Swallow::ShaderDataType::Mat4: return 4 * 4;
				case Swallow::ShaderDataType::Int: return 1;
				case Swallow::ShaderDataType::Int2: return 2;
				case Swallow::ShaderDataType::Int3: return 3;
				case Swallow::ShaderDataType::Int4: return 4;
				case Swallow::ShaderDataType::Bool: return 1;
				default:
					break;
			}
			SW_CORE_ASSERT(false, "Unknown Data Shader Data Type For count");
			return 0;
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout() {}
		BufferLayout(std::initializer_list<BufferElement> const &elements);

		inline const std::vector<BufferElement> &GetElements() const { return m_Elements; }
		inline uint32_t GetStride() const { return m_Stride; }
		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }
	private:
		void CalculateOffsetsAndStride();
	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride = 0;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void SetLayout(const BufferLayout &layout) = 0;
		virtual BufferLayout const &GetLayout() const = 0;

		static Ref<VertexBuffer> Create(void* vertices, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		inline virtual uint32_t GetCount() const = 0;

		static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);
	};
}