#include "Camera.h"

using namespace Vega;

glm::mat4 Scene::Actors::Camera::ComputeMVP()
{
	projection = glm::perspective(glm::radians(fov), aspect, nplane, fplane);
	view = glm::lookAt(pos, look, head);

	return projection * view * model;
}

