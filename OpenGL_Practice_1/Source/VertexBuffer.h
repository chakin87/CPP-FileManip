#pragma once

#include <GL/glew.h>
class VertexBuffer
{
public:// Constructor(s) / Destructor(s)
	VertexBuffer();
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();
public:// Methods

	void Bind() const;
	void Unbind() const;


private :
	unsigned int m_RendererID;
};

