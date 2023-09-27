#pragma once
#include "../Dependencies/GL.h"
#include "../Dependencies/GLM.h"

#include "../Helpers/Debug.h"
#include "../Compiler/Compiler.h"
#include "../Scene/Scene.h"
#include "../Renderer.h"

#include <memory>
#include <functional>

namespace Vega
{
	namespace Render { class Renderer; }

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
			/// Begins the rendering process.
			/// </summary>
			void Start();

			// Getters & Setters.

			GLFWwindow* GetWindow() { return window; }
			void SetWindow(GLFWwindow* window) { this->window = window; }

			std::pair<int, int> GetDimensions() { return { width, height }; }
			void SetDimensions(int width, int height) { this->width = width; this->height = height; }

			GLuint& GetSP() { return SP; }
			void SetSP(GLuint SP) { this->SP = SP; }

			std::unique_ptr<Render::Renderer>& GetRenderer() { return renderer; }
			void SetRenderer(std::unique_ptr<Render::Renderer> renderer) { this->renderer = std::move(renderer); }

			Scene::Scene& GetScene() { return scene; }
			void SetScene(Scene::Scene scene) { this->scene = scene; }

			std::function<void(Core::Window* window)> GetStartCallback() { return StartCallback; }
			void SetStartCallback(std::function<void(Core::Window* window)> StartCallback) { this->StartCallback = StartCallback; }

			std::function<void(Core::Window* window)> GetRenderCallback() { return RenderCallback; }
			void SetRenderCallback(std::function<void(Core::Window* window)> RenderCallback) { this->RenderCallback = RenderCallback; }

		private:
			GLFWwindow* window;

			int width, height;

			GLuint SP = 0; // Shader program.

			// Renderer.
			std::unique_ptr<Render::Renderer> renderer = std::make_unique<Render::Renderer>();

			Scene::Scene scene; // Scene.

			// Callbacks.

			std::function<void(Core::Window* window)> StartCallback = [](Core::Window* window) {};
			std::function<void(Core::Window* window)> RenderCallback = [](Core::Window* window) {};

		};
	}
}

