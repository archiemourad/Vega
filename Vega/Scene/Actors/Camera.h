#pragma once
#include "../../Dependencies/GLM.h"

#include "../Actor.h"

#include <string>

namespace Vega
{
	namespace Scene
	{
		namespace Actors
		{
			class Camera : public Actor
			{
			public:
				/// <summary>
				/// Camera setup and initialization.
				/// </summary>
				/// <param name="aspect"></param>
				Camera(float aspect) { this->aspect = aspect; }

				/// <summary>
				/// Generates the MVP matrix.
				/// </summary>
				/// <returns>The generated MVP matrix.</returns>
				glm::mat4 GenerateMVP();

				// Getters & Setters.

				glm::mat4 GetProjection() { return projection; }
				void SetProjection(glm::mat4 projection) { this->projection = projection; }

				glm::mat4 GetView() { return view; }
				void SetView(glm::mat4 view) { this->view = view; }

				glm::mat4 GetModel() { return model; }
				void SetModel(glm::mat4 model) { this->model = model; }

				float GetFov() { return fov; }
				void SetFov(float fov) { this->fov = fov; }

				float GetAspect() { return aspect; }
				void SetAspect(float aspect) { this->aspect = aspect; }

				float GetNPlane() { return nplane; }
				void SetNPlane(float nplane) { this->nplane = nplane; }

				float GetFPlane() { return fplane; }
				void SetFPlane(float fplane) { this->fplane = fplane; }

				glm::vec3 GetLook() { return look; }
				void SetLook(glm::vec3 look) { this->look = look; }

				void UpdateLook(glm::vec3 look) { this->look = this->look + look; }

				glm::vec3 GetHead() { return head; }
				void SetHead(glm::vec3 head) { this->head = head; }

			private:
				// Projection / View / Model

				glm::mat4 projection = glm::mat4(0.f);
				glm::mat4 view = glm::mat4(0.f);
				glm::mat4 model = glm::mat4(1.f);

				// Projection.

				float fov = 45.f;
				float aspect;
				float nplane = 0.1f;
				float fplane = 100.f;

				// View.

				glm::vec3 look = glm::vec3(0.f, 0.f, 0.f);
				glm::vec3 head = glm::vec3(0.f, 1.f, 0.f); // Head is up.

			};
		}
	}
}

