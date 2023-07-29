#pragma once
#include <Windows.h>

#include <iostream>
#include <string>

#include <chrono>
#include <ctime>

namespace Vega
{
	namespace Helpers
	{
		namespace Debug
		{
			// Log a message to the console.
			std::wstring Log(std::wstring msg);

			// Log an error message to the console and terminate the program (if fatal).
			std::wstring Error(std::wstring msg, const bool fatal = false, const int code = 0);

			namespace Time
			{
				// Get the current time.
				std::wstring GetTime();
			}

			namespace Formatting
			{
				// Trim a newline from the end of a string.
				std::wstring TrimNewline(std::wstring str);
			}
		}
	}
}

