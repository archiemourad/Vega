#pragma once
#include "../../Dependencies/GL.h"

#include "../Actor.h"

#include <vector>

namespace Vega
{
	namespace Scene
	{
		namespace Actors
		{
			class Object : public Actor
			{
			public:
				/// <summary>
				/// Refreshes buffers by calling glGenBuffers, glBindBuffer and glBufferData.
				/// </summary>
				void RefreshBuffers();

				/// <summary>
				/// Push index and vertex data into the buffers.
				/// </summary>
				/// <param name="data"></param>
				/// <returns>A success boolean (did succeed?).</returns>
				bool UpdateBuffers(const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>& data);

				// Getters & Setters.

				GLuint GetVAO() { return VAO; }
				void SetVAO(GLuint VAO) { this->VAO = VAO; }

				GLuint GetEBO() { return EBO; }
				void SetEBO(GLuint EBO) { this->EBO = EBO; }

				GLuint GetVBO() { return VBO; }
				void SetVBO(GLuint VBO) { this->VBO = VBO; }

				std::vector<unsigned int>& GetIndices() { return indices; }
				void SetIndices(std::vector<unsigned int> indices) { this->indices = indices; }

				std::vector<glm::vec3>& GetVertices() { return vertices; }
				void SetVertices(std::vector<glm::vec3> vertices) { this->vertices = vertices; }

			private:
				// Objects.

				GLuint VAO = 0;
				GLuint EBO = 0;
				GLuint VBO = 0;

				// Buffers.

				std::vector<unsigned int> indices;
				std::vector<glm::vec3> vertices = { glm::vec3(0.f, 0.f, 0.f) };

			};
		}
	}
}

