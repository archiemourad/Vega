#pragma once
// Deps.
#include "GL.h"
#include "GLM.h"

#include "Debug.h"

#include "Compiler.h"

namespace Vega
{
	namespace Core
	{
		class Window
		{
		public:
			// Window setup & initialization.
			Window(const char* title, const int width, const int height);

			// Runs the window (starts render).
			void Run();

			// Pass vertices and indices into the buffers.
			void DualPassIntoBuffers(const std::pair<std::vector<GLfloat>, std::vector<unsigned int>>& data);
			// Pass indices directly into the index buffer.
			void PassIndicesIntoBuffer(const std::vector<unsigned int>& indices);
			// Pass vertices directly into the vertex buffer.
			void PassVerticesIntoBuffer(const std::vector<GLfloat>& vertices);
		private:
			GLFWwindow* window;

			int width, height;

			std::vector<unsigned int> indices;
			std::vector<GLfloat> vertices;
		};
	}
}

