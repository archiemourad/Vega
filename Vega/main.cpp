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
	const std::pair<std::vector<GLfloat>, std::vector<unsigned int>> data = Loader::LoadObjectFile(L"Assets/Objects/suzanne.obj");
	// Pass the data into our buffers.
	window.DualPassIntoBuffers(data);

	// Run!
	Helpers::Debug::Log(L"Running!");

	window.Run();

	// Cleanup.
	Helpers::Instance::Cleanup();
}

