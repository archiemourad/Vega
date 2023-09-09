#include "../Helpers/Debug.h"
#include "../Helpers/Instance.h"
#include "../Core/Window.h"
#include "../Loader/Loader.h"

using namespace Vega;

int main()
{
	Helpers::Instance::Setup(); // Setup.

	Core::Window window("Vega Engine", 800, 600); // New window.

	// Load our file.
	const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>> data = Loader::LoadObjectFile(L"Assets/Objects/suzanne.obj");
	window.PassBuffers(data); // Pass the data into our buffers.

	Helpers::Debug::Log(L"Running!"); // Run!

	window.Run();

	Helpers::Instance::Cleanup(); // Cleanup.
}

