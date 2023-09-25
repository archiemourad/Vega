#pragma once
#include "../Dependencies/GLM.h"

namespace Vega
{
	namespace Scene
	{
		class Actor
		{
		public:
			// Getters & Setters.

			glm::vec3 GetPos() { return pos; }
			void SetPos(glm::vec3 pos) { this->pos = pos; }

			void UpdatePos(glm::vec3 pos) { this->pos = this->pos + pos; }

		protected:
			glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);

		};
	}
}

