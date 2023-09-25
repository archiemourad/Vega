#pragma once
#include "Dependencies/GL.h"
#include "Dependencies/GLM.h"

#include "Core/Window.h"

#include "Scene/Actors/Camera.h"
#include "Scene/Actors/Object.h"

#include <vector>
#include <memory>

namespace Vega
{
	namespace Core { class Window; }

	namespace Render
	{
		/// <summary>
		/// Renders the scene.
		/// </summary>
		/// <param name="window"></param>
		void Draw(Core::Window* window);
	}
}

