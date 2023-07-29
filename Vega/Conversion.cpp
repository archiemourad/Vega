#include "Conversion.h"

using namespace Vega;

std::wstring Helpers::Conversion::CSTRtoWSTR(const char* str)
{
    return std::wstring(&str[0], &str[strlen(str)]);
}

