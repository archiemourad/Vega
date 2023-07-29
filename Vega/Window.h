#pragma once
// Deps.
#include "GL.h"
#include "GLM.h"

#include "Debug.h"

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
		private:
			GLFWwindow* window;

			int width;
			int height;
		};
	}
}

