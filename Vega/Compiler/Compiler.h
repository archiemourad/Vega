#pragma once
#include "../Dependencies/GL.h"

#include "../Helpers/Conversion.h"
#include "../Compiler/Reader.h"

namespace Vega
{
	namespace Compiler
	{
		/// <summary>
		/// Compile a vertex shader.
		/// </summary>
		/// <param name="filePath"></param>
		/// <returns>A GLuint loaded with a vertex shader.</returns>
		GLuint CompileVertexShader(const std::wstring filePath);
		/// <summary>
		/// Compile a fragment shader.
		/// </summary>
		/// <param name="filePath"></param>
		/// <returns>A GLuint loaded with a fragment shader.</returns>
		GLuint CompileFragmentShader(const std::wstring filePath);

		/// <summary>
		/// Assemble a shader program.
		/// </summary>
		/// <param name="vertexShader"></param>
		/// <param name="fragmentShader"></param>
		/// <returns>A GLuint loaded with a shader program.</returns>
		GLuint AssembleShaderProgram(GLuint vertexShader, GLuint fragmentShader);
	}
}

