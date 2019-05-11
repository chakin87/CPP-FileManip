#pragma once

#include <GL/glew.h>
class IndexBuffer
{
public:// Constructor(s) / Destructor(s)
	IndexBuffer();
	IndexBuffer(const unsigned int* data, unsigned int count);  // count means element count!
																// size means bytes
	~IndexBuffer();
public:// Methods

	void Bind() const;
	void Unbind() const;


	inline unsigned int GetCount() const { return m_Count; }

private:
	unsigned int m_RendererID;
	unsigned int m_Count;


};

