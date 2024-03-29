#pragma once
#include <iostream>
#include <unordered_map>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragementSouce;
};

class Shader
{
private:
	unsigned int m_RendererID;
	//caching for uniforms
	std::string m_FilePath;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	//set uniforms
	void SetUniform1i(const std::string& name, int v0);
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
private:
	unsigned int GetUniformLocation(const std::string& name);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderProgramSource ParseShader(const std::string& filepath);
};

