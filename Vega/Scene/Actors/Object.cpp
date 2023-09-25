#include "Object.h"

using namespace Vega;

void Scene::Actors::Object::RefreshBuffers()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_DYNAMIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices.front(), GL_DYNAMIC_DRAW);
}

bool Scene::Actors::Object::UpdateBuffers(const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>& data)
{
	if (data.first.empty() || data.second.empty()) return false; // Empty check.

	indices.insert(indices.end(), data.first.begin(), data.first.end());
	vertices.insert(vertices.end(), data.second.begin(), data.second.end());

	RefreshBuffers();

	return true;
}

