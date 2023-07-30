#include "Debug.h"
#include "Instance.h"

#include "Window.h"

#include "Loader.h"

using namespace Vega;

int main()
{
	// Setup.
	Helpers::Instance::Setup();

	// New window.
	Core::Window window("Vega Engine", 800, 600);

	// Load our file.
	const std::vector<GLfloat> vertices = Loader::LoadObjectFile(L"Assets/Objects/suzanne.obj");

	// Run!
	Helpers::Debug::Log(L"Running!");

	window.Run();

	// Cleanup.
	Helpers::Instance::Cleanup();
}

