#pragma once
#include "../Dependencies/GL.h"
#include "../Dependencies/GLM.h"

#include "../Core/Window.h"

#include "../Scene/Actors/Camera.h"
#include "../Scene/Actors/Object.h"

#include <vector>
#include <memory>
#include <functional>

namespace Vega
{
	namespace Core { class Window; }

	namespace Render
	{
		class Renderer
		{
		public:
			/// <summary>
			/// Renders the scene.
			/// </summary>
			/// <param name="window"></param>
			void Draw(Core::Window* window);

			// Getters & Setters.

			std::function<void(Core::Window* window)> GetPreRenderCallback() { return PreRenderCallback; }
			void SetPreRenderCallback(std::function<void(Core::Window* window)> PreRenderCallback) { this->PreRenderCallback = PreRenderCallback; }

			std::function<void(Core::Window* window)> GetPostRenderCallback() { return PostRenderCallback; }
			void SetPostRenderCallback(std::function<void(Core::Window* window)> PostRenderCallback) { this->PostRenderCallback = PostRenderCallback; }

		private:
			// Callbacks.

			std::function<void(Core::Window* window)> PreRenderCallback = [](Core::Window* window) {};
			std::function<void(Core::Window* window)> PostRenderCallback = [](Core::Window* window) {};

		};
	}
}

