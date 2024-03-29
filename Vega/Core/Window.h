#pragma once
#include "../Dependencies/GL.h"
#include "../Dependencies/GLM.h"

#include "../Helpers/Debug.h"
#include "../Compiler/Compiler.h"

#include "../Scene/Scene.h"

#include <memory>

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
			~Window() { glfwDestroyWindow(window); }

			/// <summary>
			/// Prepares the window for rendering.
			/// </summary>
			void Setup();

			/// <summary>
			/// Cleans up after rendering is finished.
			/// </summary>
			void Cleanup();

			// Getters & Setters.

			GLFWwindow* GetWindow() { return window; }
			void SetWindow(GLFWwindow* window) { this->window = window; }

			std::pair<int, int> GetDimensions() { return { width, height }; }
			void SetDimensions(int width, int height) { this->width = width; this->height = height; }

			GLuint& GetSP() { return SP; }
			void SetSP(GLuint SP) { this->SP = SP; }

			Scene::Scene& GetScene() { return scene; }
			void SetScene(Scene::Scene scene) { this->scene = scene; }

		private:
			GLFWwindow* window;

			int width, height;

			GLuint SP = 0; // Shader program.

			Scene::Scene scene; // Scene.

		};
	}
}

