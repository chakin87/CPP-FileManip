#include "Renderer.h"
#include <iostream>
#include "Functions.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray & va, const IndexBuffer & ib, const Shader & shader) const
{

	shader.Bind();
//	shader.SetUniform4f("u_Color", r, 0.1f, 0.6f, 1.0f);

	//glBindVertexArray(vao);
	va.Bind();
	ib.Bind();

	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}

