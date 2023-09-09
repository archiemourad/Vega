#pragma once
#include "Dependencies/GL.h"
#include "Dependencies/GLM.h"

#include <vector>

namespace Vega
{
	namespace Render
	{
		/// <summary>
		/// Offload! Render.
		/// </summary>
		/// <param name="window"></param>
		/// <param name="SP"></param>
		/// <param name="EBO"></param>
		/// <param name="VBO"></param>
		/// <param name="indices"></param>
		/// <param name="vertices"></param>
		void Render(
			GLFWwindow* window,
			const GLuint& SP,
			// Buffer objects.
			const GLuint& EBO,
			const GLuint& VBO,
			// Buffers.
			const std::vector<unsigned int>& indices,
			const std::vector<glm::vec3>& vertices
		);
	}
}

