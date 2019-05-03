#include "Renderer.h"
#include <iostream>


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

void GLCheckError() {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << ")\n";
	}
}

bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error]   |" << error << "| \n"
			<< "[Funtion]        |" << function << "|\n"
			<< "[Line]           |" << file << "|\n"
			<< "[Line]           |" << line << "|\n";
		return false;
	}
	return true;
}