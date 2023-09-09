#pragma once
#include <iostream>

namespace Vega
{
	namespace Helpers
	{
		namespace Conversion
		{
			/// <summary>
			/// Convert a C-style string (cstr) into a wide string (wstring).
			/// </summary>
			/// <param name="str"></param>
			/// <returns>The converted (w)string.</returns>
			std::wstring CSTRtoWSTR(const char* str);
		}
	}
}

