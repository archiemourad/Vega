#pragma once
#include "GL.h"

#include "Debug.h"

#include <fstream>
#include <map>

namespace Vega
{
	namespace Loader
	{
		/// <summary>
		/// Reads the contents of an object file (multiline).
		/// </summary>
		/// <param name="filePath"></param>
		/// <returns>A pair containing the object's vertex and index data.</returns>
		std::pair<std::vector<GLfloat>, std::vector<unsigned int>> LoadObjectFile(const std::wstring filePath);

		/// <summary>
		/// Reads the contents of an object file (multiline).
		/// </summary>
		/// <param name="filePath"></param>
		/// <returns>A pair containing a success boolean (did succeed?) and the object's vertices.</returns>
		std::pair<bool, std::vector<GLfloat>> LoadObjectVertices(const std::wstring filePath);
		/// <summary>
		/// Computes the indices for an item based of it's vertices.
		/// </summary>
		/// <param name="vertices"></param>
		/// <returns>A pair containing a success boolean (did succeed?) and the generated indices.</returns>
		std::pair<bool, std::vector<unsigned int>> ComputeIndices(const std::vector<GLfloat>& vertices);
	}
}

