#include "Loader.h"

using namespace Vega;

std::vector<GLfloat> Loader::LoadObjectFile(const std::wstring filePath)
{
    std::ifstream file(filePath);

    std::vector<GLfloat> output;
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::string prefix;
            std::istringstream iss(line);
            iss >> prefix;

            if (prefix == "v") {
                GLfloat x, y, z;
                iss >> x >> y >> z;

                output.insert(output.end(), { x, y, z });
            }
        }

        file.close();

        Helpers::Debug::Log(L"Loaded object file: " + filePath + L"!");
    } else {
        Helpers::Debug::Error(L"Failed to open file: " + filePath + L"!");
    }

    return output;
}

