#pragma once
#include "../Helpers/Debug.h"

#include <fstream>

namespace Vega
{
	namespace Compiler
	{
		namespace Reader
		{
			/// <summary>
			/// Read the contents of a file (multiline).
			/// </summary>
			/// <param name="filePath"></param>
			/// <returns>A string loaded with the contents of the file.</returns>
			std::string ReadFile(const std::wstring filePath);
		}
	}
}

