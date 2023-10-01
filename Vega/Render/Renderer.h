#pragma once
#include "../Dependencies/GL.h"
#include "../Dependencies/GLM.h"

#include "../Core/Window.h"
#include "../Misc/Vertex/Vertex.h"

#include "../Scene/Actors/Camera.h"
#include "../Scene/Actors/Object.h"

#include <memory>
#include <functional>

namespace Vega
{
	namespace Render
	{
		class Renderer
		{
		public:
			/// <summary>
			/// Renders the scene.
			/// </summary>
			/// <param name="window"></param>
			void Draw(std::shared_ptr<Core::Window> window);

			// Getters & Setters.

			std::function<void(std::shared_ptr<Core::Window> window)> GetPreRenderCallback() { return PreRenderCallback; }
			void SetPreRenderCallback(std::function<void(std::shared_ptr<Core::Window> window)> PreRenderCallback) { this->PreRenderCallback = PreRenderCallback; }

			std::function<void(std::shared_ptr<Core::Window> window)> GetPostRenderCallback() { return PostRenderCallback; }
			void SetPostRenderCallback(std::function<void(std::shared_ptr<Core::Window> window)> PostRenderCallback) { this->PostRenderCallback = PostRenderCallback; }

		private:
			// Callbacks.

			std::function<void(std::shared_ptr<Core::Window> window)> PreRenderCallback = [](std::shared_ptr<Core::Window> window) {};
			std::function<void(std::shared_ptr<Core::Window> window)> PostRenderCallback = [](std::shared_ptr<Core::Window> window) {};

		};
	}
}

