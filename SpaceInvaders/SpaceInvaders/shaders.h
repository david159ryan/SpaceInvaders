#pragma once
#include <main.h>

namespace Shaders 
{
	GLuint LoadShaders(const char* vertShaderPath, const char* fragShaderPath);
	std::string LoadFileToString(const char* filepath);
}
