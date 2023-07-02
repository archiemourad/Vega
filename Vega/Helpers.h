#pragma once
#include <string>

#include "Dependencies.h"

namespace Vega
{
	namespace Helpers
	{
		/* Helpers */
		// (Arrow Format) Formats two (wide) strings together using an arrow (->).
		std::wstring AFormat(std::wstring str, std::wstring strTwo);

		/* Utility */
		// Prints a one part, or two part message to the debug output.
		std::wstring Output(std::wstring str, std::wstring strTwo = std::wstring(), std::wstring origin = L"Vega");
	}
}

