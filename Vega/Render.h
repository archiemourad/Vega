#pragma once
#include "Dependencies/GL.h"
#include "Dependencies/GLM.h"

#include "Core/Window.h"
#include "Scene/Actors/Camera.h"

#include <vector>

namespace Vega
{
	namespace Core { class Window; }

	namespace Render
	{
		/// <summary>
		/// Renders the scene.
		/// </summary>
		/// <param name="window"></param>
		void Render(Core::Window* window);
	}
}

