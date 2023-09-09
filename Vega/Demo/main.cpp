#include "../Helpers/Debug.h"
#include "../Helpers/Instance.h"
#include "../Core/Window.h"
#include "../Loader/Loader.h"

using namespace Vega;

int main()
{
	// Setup.
	Helpers::Instance::Setup();

	// New window.
	Core::Window window("Vega Engine", 800, 600);

	// Load our file.
	const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>> data = Loader::LoadObjectFile(L"Assets/Objects/suzanne.obj");
	// Pass the data into our buffers.
	window.PassBuffers(data);

	// Run!
	Helpers::Debug::Log(L"Running!");

	window.Run();

	// Cleanup.
	Helpers::Instance::Cleanup();
}

