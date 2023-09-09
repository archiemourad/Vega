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
			/// <param name="data">A success boolean (did succeed?).</param>
			bool PassBuffers(const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>& data);
		private:
			GLFWwindow* window;

			int width, height;

			std::vector<unsigned int> indices;
			std::vector<glm::vec3> vertices = { glm::vec3(0, 0, 0) };
		};
	}
}

