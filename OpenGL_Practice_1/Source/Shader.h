#pragma once

#include <unordered_map>
#include <string>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{

private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	// Caching for uniforms
	std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const std::string& filepath);
	Shader();
	~Shader();
public:// Methods
	void Bind() const;
	void Unbind() const;



	// Set uniforms
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:// Methods
	ShaderProgramSource ParseShader(const std::string& filePath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string fragmentShader);

	int GetuniformLocation(const std::string& name);
	bool CompileShader();
};

