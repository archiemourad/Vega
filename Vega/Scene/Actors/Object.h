#pragma once
#include "../../Dependencies/GL.h"

#include "../Actor.h"
#include "../../Misc/Vertex/Vertex.h"
#include "../../Misc/Texture/Texture.h"

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
				bool UpdateBuffers(const std::pair<std::vector<unsigned int>, std::vector<Misc::Vertex::Vertex>>& data);

				// Getters & Setters.

				GLuint GetVAO() { return VAO; }
				void SetVAO(GLuint VAO) { this->VAO = VAO; }

				GLuint GetEBO() { return EBO; }
				void SetEBO(GLuint EBO) { this->EBO = EBO; }

				GLuint GetVBO() { return VBO; }
				void SetVBO(GLuint VBO) { this->VBO = VBO; }

				std::vector<unsigned int>& GetIndices() { return indices; }
				void SetIndices(std::vector<unsigned int> indices) { this->indices = indices; }

				std::vector<Misc::Vertex::Vertex>& GetVertices() { return vertices; }
				void SetVertices(std::vector<Misc::Vertex::Vertex> vertices) { this->vertices = vertices; }

				Misc::Texture::Texture& GetTexture() { return texture; }
				void SetTexture(Misc::Texture::Texture texture) { this->texture = texture; }

			private:
				// Objects.

				GLuint VAO = 0;
				GLuint EBO = 0;
				GLuint VBO = 0;

				// Buffers.

				std::vector<unsigned int> indices;
				std::vector<Misc::Vertex::Vertex> vertices = { {glm::vec3(0.f, 0.f, 0.f), glm::vec2(0.f, 0.f)} };

				Misc::Texture::Texture texture; // Texture.

			};
		}
	}
}

