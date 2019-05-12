#include "Shader.h"
//#include "Renderer.h"
#include "Functions.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



Shader::Shader()
{
}



Shader::Shader(const std::string & filepath):
	m_FilePath(filepath), m_RendererID(0)
{
	// TODO: Fix this hard coded filePath
	ShaderProgramSource source = ParseShader("Resources/Shaders/basic.shader");
	m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader()
{
	glDeleteProgram(m_RendererID);
}

void Shader::SetUniform1i(const std::string & name, int value)
{
	glUniform1i(GetuniformLocation(name), value);
}

void Shader::SetUniform1f(const std::string & name, float value)
{
	glUniform1f(GetuniformLocation(name), value);
}

void Shader::SetUniform4f(const std::string & name, float v0, float v1, float v2, float v3)
{
	glUniform4f(GetuniformLocation(name), v0, v1, v2, v3);
}

void Shader::Bind() const
{
	glUseProgram(m_RendererID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}
int Shader::GetuniformLocation(const std::string & name)
{

	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
		return m_UniformLocationCache[name];
	}

	int location = glGetUniformLocation(m_RendererID, name.c_str());

	if (location == -1)
		std::cout << "Warning: Uniform '" << name << "' d.n.e.!\n";
	m_UniformLocationCache[name] = location;
	return location;
}

bool Shader::CompileShader()
{
	return false;
}




 ShaderProgramSource Shader::ParseShader(const std::string& filePath) {

	std::ifstream stream(filePath);
	// TODO: error handeling for file open

	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line)) {

		if (line.find("#shader") != std::string::npos) {

			if (line.find("vertex") != std::string::npos) {
				//set mode to vertex
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				//set mode to fragment
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			//std::cout << "\n\nType: " << (int)type << "\n\n";
			ss[(int)(type)] << line << '\n';
		}
	}
	return { ss[0].str(), ss[1].str() };
}





unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {

	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	// TODO: assert shader compilation...

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		// Work-around for char message[length]; 
		// This is a stack allocated array with a non-predetermined size!
		char* message = (char*)alloca(length * sizeof(char));

		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " <<
			(type == GL_VERTEX_SHADER ? "vertex:\n" : "fragment:\n") << message;
		glDeleteShader(id);
		return 0;
	}



	return id;
}


unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string fragmentShader) {

	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}
