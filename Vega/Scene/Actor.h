#pragma once
#include "../Dependencies/GLM.h"

namespace Vega
{
	namespace Scene
	{
		class Actor
		{
		public:
			/// <summary>
			/// Computes the model matrix.
			/// </summary>
			/// <returns>The computed model matrix.</returns>
			glm::mat4 ComputeModel();

			// Getters & Setters.

			glm::vec3 GetPos() { return pos; }
			void SetPos(glm::vec3 pos) { this->pos = pos; }

			void UpdatePos(glm::vec3 pos) { this->pos = this->pos + pos; }

			glm::mat4 GetTranslation() { return translation; }
			void SetTranslation(glm::mat4 translation) { this->translation = translation; }

			float GetAngle() { return angle; }
			void SetAngle(float angle) { this->angle = angle; }

			void UpdateAngle(float angle) { this->angle = this->angle + angle; }

			glm::vec3 GetAxis() { return axis; }
			void SetAxis(glm::vec3 axis) { this->axis = axis; }

			glm::mat4 GetRotation() { return rotation; }
			void SetRotation(glm::mat4 rotation) { this->rotation = rotation; }

			glm::vec3 GetScale() { return scale; }
			void SetScale(glm::vec3 scale) { this->scale = scale; }

			void UpdateScale(glm::vec3 scale) { this->scale = this->scale + scale; }

			glm::mat4 GetScaling() { return scaling; }
			void SetScaling(glm::mat4 scaling) { this->scaling = scaling; }

			// Not to be confused with ComputeModel.
			glm::mat4 GetModel() { return model; }
			void SetModel(glm::mat4 model) { this->model = model; }

		protected:
			// Position.

			glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);

			glm::mat4 translation = glm::mat4(0.f);

			// Rotation.

			float angle = 0.f;
			glm::vec3 axis = glm::vec3(0.f, 1.f, 0.f);

			glm::mat4 rotation = glm::mat4(0.f);

			// Scaling.

			glm::vec3 scale = glm::vec3(1.f, 1.f, 1.f);

			glm::mat4 scaling = glm::mat4(0.f);


			glm::mat4 model = glm::mat4(1.f); // ***

		};
	}
}

