#pragma once
// Deps.
#include "GL.h"

#include "Debug.h"

#include <fstream>

namespace Vega
{
	namespace Loader
	{
		// Reads the contents of an object file (multiline).
		std::vector<GLfloat> LoadObjectFile(const std::wstring filePath);
	}
}

