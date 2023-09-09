#pragma once
#include "../Dependencies/GL.h"
#include "../Dependencies/GLM.h"

#include "../Helpers/Debug.h"
#include "../Compiler/Compiler.h"
#include "../Render.h"

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
			/// <returns>A success boolean (did succeed?).</returns>
			bool PassBuffers(const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>& data);
		private:
			GLFWwindow* window;

			int width, height;

			std::vector<unsigned int> indices;
			std::vector<glm::vec3> vertices = { glm::vec3(0, 0, 0) };
		};
	}
}
