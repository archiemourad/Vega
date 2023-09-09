#include "Compiler.h"

using namespace Vega;

GLuint Compiler::CompileVertexShader(const std::wstring filePath)
{
	GLuint VS;
	VS = glCreateShader(GL_VERTEX_SHADER);

	const std::string data = Reader::ReadFile(filePath);
	const char* source = data.c_str();

	glShaderSource(VS, 1, &source, NULL);
	glCompileShader(VS);

	int success;
	char log[512];

	glGetShaderiv(VS, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(VS, 512, NULL, log);
		Helpers::Debug::Error(L"(" + filePath + L") Vertex shader compilation failed:\n" + Helpers::Conversion::CSTRtoWSTR(log));
	}
	else {
		Helpers::Debug::Log(L"Compiled vertex shader: " + filePath + L"!");
	}

	return VS;
}

GLuint Compiler::CompileFragmentShader(const std::wstring filePath)
{
	GLuint FS;
	FS = glCreateShader(GL_FRAGMENT_SHADER);

	const std::string data = Reader::ReadFile(filePath);
	const char* source = data.c_str();

	glShaderSource(FS, 1, &source, NULL);
	glCompileShader(FS);

	int success;
	char log[512];

	glGetShaderiv(FS, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(FS, 512, NULL, log);
		Helpers::Debug::Error(L"(" + filePath + L") Fragment shader compilation failed:\n" + Helpers::Conversion::CSTRtoWSTR(log));
	}
	else {
		Helpers::Debug::Log(L"Compiled fragment shader: " + filePath + L"!");
	}

	return FS;
}

GLuint Compiler::AssembleShaderProgram(GLuint vertexShader, GLuint fragmentShader)
{
	GLuint SP;
	SP = glCreateProgram();

	glAttachShader(SP, vertexShader);
	glAttachShader(SP, fragmentShader);

	glLinkProgram(SP);

	int success;
	char log[512];

	glGetProgramiv(SP, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(SP, 512, NULL, log);
		Helpers::Debug::Error(L"Shader program linking failed:\n" + Helpers::Conversion::CSTRtoWSTR(log));
	}
	else {
		Helpers::Debug::Log(L"Assembled shader program!");
	}

	return SP;
}

