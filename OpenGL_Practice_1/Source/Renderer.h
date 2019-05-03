#pragma once
#include <GL/glew.h>

class Renderer
{
public:
	Renderer();
	~Renderer();
};
	



#define ASSERT(X) if (!(X)) __debugbreak();

#define GLCall(X) GLClearError();\
	X;\
	ASSERT(GLLogCall(#X, __FILE__, __LINE__));

void GLClearError();

void GLCheckError();

bool GLLogCall(const char* function, const char* file, int line);
