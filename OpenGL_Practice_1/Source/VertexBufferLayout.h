#pragma once

#include <vector>
#include <GL/glew.h>
#include "Renderer.h"


struct VertexBufferElement {

	unsigned int type;
	unsigned int count;
	unsigned char normalized; 

	static unsigned int GetSizeOfType(unsigned int type) {
		switch (type) {
			case GL_FLOAT: return 4; break;
			case GL_UNSIGNED_INT: return 4;  
			case GL_UNSIGNED_BYTE: return 1;
		}
		ASSERT(false);
		return 0;
	}

};


class VertexBufferLayout {
public:
	VertexBufferLayout() :
		m_Stride(0) {}

	template<typename T>
	void Push(int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(int count) 
	{
		m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}
	template<>
	void Push<unsigned int>(int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += sizeof(GLuint);
	}
	template<>
	void Push<unsigned char>(int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += sizeof(GLbyte);
	}

	inline unsigned int GetStride() const { return m_Stride; }
	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }


private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
	
};