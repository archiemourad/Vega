#include "Actor.h"

using namespace Vega;

glm::mat4 Vega::Scene::Actor::ComputeModel()
{
	translation = glm::translate(glm::mat4(1.f), pos);
	rotation = glm::rotate(glm::mat4(1.f), glm::radians(angle), axis);
	scaling = glm::scale(glm::mat4(1.f), scale);

	model = translation * rotation * scaling;

	return model;
}

