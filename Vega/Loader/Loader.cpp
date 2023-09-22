#include "Loader.h"

using namespace Vega;

std::pair<std::vector<unsigned int>, std::vector<glm::vec3>> Loader::LoadObjectFile(const std::wstring filePath)
{
	bool result = true;

	Helpers::Debug::Log(L"Loading object file: " + filePath + L"!");

	const std::pair<bool, std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>> data = ReadObjectFile(filePath);

	if (!data.first) result = false;

	std::wstring reading = result ? L"Success!" : L"Failed!";
	Helpers::Debug::DentLog(L"Reading: " + reading);

	if (!result) {
		Helpers::Debug::Log(L"Warning! Fallback. Object loading failed.");

		return { std::vector<unsigned int>{ 0 }, std::vector<glm::vec3>{ glm::vec3(0.f, 0.f, 0.f) } };
	}

	return { data.second.first, data.second.second };
}

std::pair<bool, std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>> Loader::ReadObjectFile(const std::wstring filePath)
{
	bool result = true;

	std::ifstream file(filePath);

	std::vector<unsigned int> indices;
	std::vector<glm::vec3> vertices;

	std::string line;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			std::string prefix;
			std::istringstream iss(line);
			iss >> prefix;

			if (prefix == "v") {
				glm::vec3 vertex;
				iss >> vertex.x >> vertex.y >> vertex.z;

				vertices.push_back(vertex);
			}

			std::replace(line.begin(), line.end(), '/', ' '); // Format.
			std::istringstream fiss(line);
			fiss >> prefix;

			if (prefix == "f") {
				unsigned int values[3] = { 0, 0, 0 };

				std::string word;
				unsigned int pos = 0;

				for (unsigned int i = 0; i < 9; i++) {
					fiss >> word;

					if (i % 3 == 0) {
						values[pos] = stoi(word);
						pos++;
					}
				}

				for (unsigned int value : values) indices.push_back(value);
			}
		}

		file.close();
	}
	else {
		result = false;
	}

	if (indices.empty() || vertices.empty()) result = false;

	return { result, { indices, vertices } };
}

