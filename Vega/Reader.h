#pragma once
#include "Debug.h"

#include <fstream>

namespace Vega
{
	namespace Compiler
	{
		namespace Reader
		{
			// Read the contents of a file (multiline).
			std::string ReadFile(const std::wstring filePath);
		}
	}
}

