#include "Reader.h"

using namespace Vega;

std::string Compiler::Reader::ReadFile(const std::wstring filePath)
{
    std::ifstream file(filePath);

    std::string output, line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            output += (line + "\n");
        }

        file.close();

        Helpers::Debug::Log(L"Read file: " + filePath + L"!");
    } else {
        Helpers::Debug::Error(L"Failed to open file: " + filePath + L"!");
    }

    return output;
}

