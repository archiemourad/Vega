#include "Loader.h"

using namespace Vega;

std::pair<std::vector<GLfloat>, std::vector<unsigned int>> Loader::LoadObjectFile(const std::wstring filePath)
{
	Helpers::Debug::Log(L"Loading object file: " + filePath + L"!");

	const std::pair<bool, std::vector<GLfloat>> vertices = LoadObjectVertices(filePath);
	const std::pair<bool, std::vector<unsigned int>> indices = ComputeIndices(vertices.second);

	std::wstring result;

	result = vertices.first ? L"Success!" : L"Failed!";
	Helpers::Debug::DentLog(L"Vertex loading: " + result);

	result = indices.first ? L"Success!" : L"Failed!";
	Helpers::Debug::DentLog(L"Index computation: " + result);

	if (!vertices.first && !indices.first) {
		Helpers::Debug::Log(L"Warning! Object [" + filePath + L"] loading & index computation failed.");
	}

	return { vertices.second, indices.second };
}

std::pair<bool, std::vector<GLfloat>> Loader::LoadObjectVertices(const std::wstring filePath)
{
	bool result = true;

	std::ifstream file(filePath);

	std::vector<GLfloat> vertices;
	std::string line;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			std::string prefix;
			std::istringstream iss(line);
			iss >> prefix;

			if (prefix == "v") {
				GLfloat x, y, z;
				iss >> x >> y >> z;

				vertices.insert(vertices.end(), { x, y, z });
			}
		}

		file.close();
	}
	else {
		result = false;
	}

	if (vertices.empty()) result = false;

	return { result, vertices };
}

std::pair<bool, std::vector<unsigned int>> Loader::ComputeIndices(const std::vector<GLfloat>& vertices)
{
	bool result = true;

	std::map<unsigned int, GLfloat> map;

	bool found = false;

	for (unsigned int i = 0; i < vertices.size(); i++) {
		found = false;

		for (const auto& [key, value] : map) {
			if (value == vertices[i]) {
				map.insert({ key, vertices[i] });
				found = true;
			};

			break;
		}

		if (!found) map.insert({ i, vertices[i] });
	}

	std::vector<unsigned int> indices;
	indices.reserve(map.size());

	for (const auto& [key, value] : map) {
		indices.push_back(key);
	}

	if (indices.empty()) result = false;

	return { result, indices };
}

