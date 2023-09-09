#pragma once
#include "../Dependencies/GL.h"
#include "../Dependencies/GLM.h"

#include "../Helpers/Debug.h"

#include <fstream>
#include <algorithm>

namespace Vega
{
	namespace Loader
	{
		/// <summary>
		/// Reads the contents of an object file (multiline).
		/// </summary>
		/// <param name="filePath"></param>
		/// <returns>A pair containing the object's index and vertex data.</returns>
		std::pair<std::vector<unsigned int>, std::vector<glm::vec3>> LoadObjectFile(const std::wstring filePath);

		/// <summary>
		/// Reads the contents of an object file (multiline).
		/// </summary>
		/// <param name="filePath"></param>
		/// <returns>A pair containing a success boolean (did succeed?) and another pair containing the object's index and vertex data.</returns>
		std::pair<bool, std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>> ReadObjectFile(const std::wstring filePath);
	}
}

