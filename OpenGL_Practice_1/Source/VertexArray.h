#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"


class VertexArray
{
public:
	VertexArray();
	~VertexArray();

public:// Methods

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void Bind() const;
	void Unbind() const;



private://Members
	unsigned int m_RendererID;
};

