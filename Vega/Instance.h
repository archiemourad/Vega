#pragma once
#include "GL.h"

#include "Debug.h"

namespace Vega
{
	namespace Helpers
	{
		namespace Instance
		{
			/// <summary>
			/// Primitive setup.
			/// </summary>
			void Setup();

			/// <summary>
			/// GLFW termination and primitive cleanup.
			/// </summary>
			void Cleanup();
		}
	}
}

