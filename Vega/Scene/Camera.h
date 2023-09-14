#pragma once
#include "../Dependencies/GLM.h"

#include <string>

namespace Vega
{
	namespace Scene
	{
		class Camera
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
			/// <returns></returns>
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

			glm::vec3 GetPos() { return pos; }
			void SetPos(glm::vec3 pos) { this->pos = pos; }

			void UpdatePos(glm::vec3 pos) { this->pos = this->pos + pos; }

			glm::vec3 GetLook() { return look; }
			void SetLook(glm::vec3 look) { this->look = look; }

			void UpdateLook(glm::vec3 look) { this->look = this->look + look; }

			glm::vec3 GetHead() { return head; }
			void SetHead(glm::vec3 head) { this->head = head; }
		private:
			// Projection / View / Model
			glm::mat4 projection = glm::mat4(0.0f);
			glm::mat4 view = glm::mat4(0.0f);
			glm::mat4 model = glm::mat4(1.0f);

			// Projection.
			float fov = 45.0f;
			float aspect;
			float nplane = 0.1f;
			float fplane = 100.0f;
			// View.
			glm::vec3 pos = glm::vec3(0, 0, 0);
			glm::vec3 look = glm::vec3(0, 0, 0);
			glm::vec3 head = glm::vec3(0, 1, 0); // Head is up.
		};
	}
}

