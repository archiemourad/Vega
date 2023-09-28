#include "Loader.h"

using namespace Vega;

std::pair<std::vector<unsigned int>, std::vector<Misc::Vertex::Vertex>> Loader::LoadObjectFile(const std::wstring filePath)
{
	bool result = true;

	Helpers::Debug::Log(L"Loading object file: " + filePath + L"!");

	const std::pair<bool, std::pair<std::vector<unsigned int>, std::vector<Misc::Vertex::Vertex>>> data = ReadObjectFile(filePath);

	if (!data.first) result = false;

	std::wstring reading = result ? L"Success!" : L"Failed!";
	Helpers::Debug::DentLog(L"Reading: " + reading);

	if (!result) {
		Helpers::Debug::Log(L"Warning! Fallback. Object loading failed.");

		return { std::vector<unsigned int>{ 0 }, std::vector<Misc::Vertex::Vertex>{ {glm::vec3(0.f, 0.f, 0.f), glm::vec2(0.f, 0.f)} } };
	}

	return { data.second.first, data.second.second };
}

std::pair<bool, std::pair<std::vector<unsigned int>, std::vector<Misc::Vertex::Vertex>>> Loader::ReadObjectFile(const std::wstring filePath)
{
	bool result = true;

	std::ifstream file(filePath);

	std::vector<unsigned int> indices;
	std::vector<Misc::Vertex::Vertex> vertices;

	std::vector<glm::vec2> texcoords;

	std::string line;

	if (file.is_open()) {
		while (std::getline(file, line)) {
			std::string prefix;
			std::istringstream iss(line);
			iss >> prefix;

			if (prefix == "v") {
				Misc::Vertex::Vertex vertex;
				iss >> vertex.position.x >> vertex.position.y >> vertex.position.z;

				vertices.push_back(vertex);
			}

			if (prefix == "vt") {
				glm::vec2 texcoord;
				iss >> texcoord.x >> texcoord.y;

				texcoords.push_back(texcoord);
			}

			std::replace(line.begin(), line.end(), '/', ' '); // Format.
			std::istringstream fiss(line);
			fiss >> prefix;

			if (prefix == "f") {
				std::vector<glm::vec3> vecs;

				// Get data.
				for (unsigned int i = 0; i < 3; i++) {
					glm::vec3 vec = glm::vec3(0.f, 0.f, 0.f);

					std::string word;

					for (unsigned int i = 0; i < 3; i++) {
						fiss >> word;
						vec[i] = stoi(word);
					}

					vecs.push_back(vec); // Update.
				}

				for (glm::vec3 vec : vecs) {
					indices.push_back(vec[0]);
					vertices[vec[0] - 1].texCoord = texcoords[vec[1] - 1];
				}
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

