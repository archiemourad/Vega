#pragma once
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
			/// <summary>
			/// Window setup and initialization.
			/// </summary>
			/// <param name="title"></param>
			/// <param name="width"></param>
			/// <param name="height"></param>
			Window(const char* title, const int width, const int height);

			/// <summary>
			/// Begins the rendering process.
			/// </summary>
			void Run();

			/// <summary>
			/// Pass vertices and indices into the buffers.
			/// </summary>
			/// <param name="data"></param>
			void DualPassIntoBuffers(const std::pair<std::vector<GLfloat>, std::vector<unsigned int>>& data);

			/// <summary>
			/// Unsafe! Pass indices directly into the index buffer.
			/// </summary>
			/// <param name="indices"></param>
			void PassIndicesIntoBuffer(const std::vector<unsigned int>& indices);
			/// <summary>
			/// Unsafe! Pass vertices directly into the vertex buffer.
			/// </summary>
			/// <param name="vertices"></param>
			void PassVerticesIntoBuffer(const std::vector<GLfloat>& vertices);
		private:
			GLFWwindow* window;

			int width, height;

			std::vector<unsigned int> indices{ 1 };
			std::vector<GLfloat> vertices{ 0, 0, 0 };
		};
	}
}

