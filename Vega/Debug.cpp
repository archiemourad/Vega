#include "Debug.h"

using namespace Vega;

std::wstring Helpers::Debug::Log(std::wstring msg)
{
    msg = L"[" + Time::GetTime() + L"] Log -> " + msg;

    std::wcout << msg << "\n";

    return msg;
}

std::wstring Vega::Helpers::Debug::DentLog(std::wstring msg, int count)
{
    std::wstring indents;
    for (unsigned int i = 0; i < count; i++) indents += L"\t";

    msg = indents + L" -> \t" + msg;

    std::wcout << msg << "\n";

    return msg;
}

std::wstring Helpers::Debug::Error(std::wstring msg, bool fatal, int code)
{
    MessageBox(NULL, msg.c_str(), L"Error", MB_ICONERROR | MB_OK);

    msg = L"[" + Time::GetTime() + L"] Error! -> " + msg;

    std::wcout << msg << "\n";

    if (fatal) {
        exit(code);
    }

    return msg;
}

std::wstring Helpers::Debug::Time::GetTime()
{
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char buffer[100];
    ctime_s(buffer, sizeof(buffer), &now);

    return Formatting::TrimNewline(std::wstring(&buffer[0], &buffer[strlen(buffer)]));
}

std::wstring Helpers::Debug::Formatting::TrimNewline(std::wstring str)
{
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
    return str;
}

