#include "Instance.h"

using namespace Vega;

void Helpers::Instance::Setup()
{
	glewExperimental = true;

	if (!glfwInit()) Helpers::Debug::Error(L"Failed to initialize GLFW.");
}

void Helpers::Instance::Cleanup() { glfwTerminate(); }

