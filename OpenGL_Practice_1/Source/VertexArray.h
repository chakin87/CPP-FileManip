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




private://Members
	unsigned int m_Rende;//video 14; TimeStamp: 22:40
};

