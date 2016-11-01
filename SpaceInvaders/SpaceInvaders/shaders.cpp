#include <Shaders.h>

namespace Shaders 
{

	GLuint LoadShaders(const char* vertShaderPath, const char* fragShaderPath)
	{

		GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);


		std::string vertShaderSource = LoadFileToString(vertShaderPath);
		std::string fragShaderSource = LoadFileToString(fragShaderPath);

		const char* rawVertShaderSource = vertShaderSource.c_str();
		const char* rawFragShaderSource = fragShaderSource.c_str();

		glShaderSource(vertShader, 1, &rawVertShaderSource, NULL);
		glShaderSource(fragShader, 1, &rawFragShaderSource, NULL);

		glCompileShader(vertShader);
		glCompileShader(fragShader);

		GLuint program = glCreateProgram();
		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);

		return program;
	}

	std::string LoadFileToString(const char* filepath)
	{
		std::string fileData = "";
		std::ifstream stream(filepath, std::ios::in);

		if (stream.is_open()) {
			std::string line = "";

			while (getline(stream, line)) {
				fileData += "\n" + line;
			}

			stream.close();
		}
		return fileData;
	}

}

