#pragma once
// Deps.
#include "GL.h"

#include "Debug.h"

#include <fstream>
#include <map>

namespace Vega
{
	namespace Loader
	{
		// Reads the contents of an object file (multiline).
		std::pair<std::vector<GLfloat>, std::vector<unsigned int>> LoadObjectFile(const std::wstring filePath);

		// Read the vertices of an object file (multiline).
		std::pair<bool, std::vector<GLfloat>> LoadObjectVertices(const std::wstring filePath);
		// Compute indices of an object using its vertices.
		std::pair<bool, std::vector<unsigned int>> ComputeIndices(const std::vector<GLfloat>& vertices);
	}
}

