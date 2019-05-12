#pragma once
#include <GL/glew.h>
#include "VertexArray.h"
#include "Shader.h"
#include "IndexBuffer.h"

class Renderer
{
public: // Constructors/Destructors
	Renderer();
	~Renderer();

public: // Methods
	void Clear();
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;

private:
private:
};
	

