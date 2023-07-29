#pragma once
// Deps.
#include "GL.h"

#include "Conversion.h"

#include "Reader.h"

namespace Vega
{
	namespace Compiler
	{
		// Compile a vertex shader.
		GLuint CompileVertexShader(const std::wstring filePath);
		// Compile a fragment shader.
		GLuint CompileFragmentShader(const std::wstring filePath);

		// Assemble a shader program.
		GLuint AssembleShaderProgram(GLuint vertexShader, GLuint fragmentShader);
	}
}

