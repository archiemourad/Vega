#include "Helpers.h"

using namespace Vega;

std::wstring Helpers::AFormat(std::wstring str, std::wstring strTwo)
{
    return str + L" -> " + strTwo;
}

std::wstring Helpers::Output(std::wstring str, std::wstring strTwo, std::wstring origin)
{
    std::wstring msg = str;

    if (strTwo != std::wstring())
        msg = AFormat(str, strTwo);

    OutputDebugString((L"Vega (" + origin + L"): " + msg + L"\n").c_str());
    return msg;
}

