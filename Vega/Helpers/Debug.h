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
			/// <summary>
			/// Log a message to the console (including timestamp).
			/// </summary>
			/// <param name="msg"></param>
			/// <returns>The formatted message that was logged to console.</returns>
			std::wstring Log(std::wstring msg);
			/// <summary>
			/// Log an indented (tree-style) message to the console (without timestamp).
			/// </summary>
			/// <param name="msg"></param>
			/// <param name="count"></param>
			/// <returns>The formatted message that was logged to console.</returns>
			std::wstring DentLog(std::wstring msg, int count = 1);

			/// <summary>
			/// Log an error message to the console and terminate the program (if the error was fatal).
			/// </summary>
			/// <param name="msg"></param>
			/// <param name="fatal"></param>
			/// <param name="code"></param>
			/// <returns>The formatted (error) message that was logged to console.</returns>
			std::wstring Error(std::wstring msg, bool fatal = false, int code = 0);

			namespace Time
			{
				/// <summary>
				/// Get the current time in the form of [(Name of Day) (Month) (Day of Month) (Hour: 24hr Time):(Minute):(Second) (Year)].
				/// </summary>
				/// <returns>The current time.</returns>
				std::wstring GetTime();
			}

			namespace Formatting
			{
				/// <summary>
				/// Trim the newline character from the end of a string.
				/// </summary>
				/// <param name="str"></param>
				/// <returns>The trimmed string.</returns>
				std::wstring TrimNewline(std::wstring str);
			}
		}
	}
}

