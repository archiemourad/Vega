#include "../Helpers/Debug.h"
#include "../Helpers/Instance.h"
#include "../Core/Window.h"
#include "../Loader/Loader.h"

using namespace Vega;

int main()
{
	Helpers::Instance::Setup(); // Setup.

	Core::Window _window("Vega Engine", 800, 600); // New window.
	Core::Window* window = &_window;

	const auto data = Loader::LoadObjectFile(L"Assets/Objects/suzanne.obj"); // Load our file.
	window->PassBuffers(data); // Pass the data into our buffers.

	// Create our camera.
	std::shared_ptr<Scene::Camera> camera = window->PublishCamera(window->CreateCamera(glm::vec3(5.0f, 5.0f, -5.0f)));

	Helpers::Debug::Log(L"Running!"); // Run!

	window->Run();

	Helpers::Instance::Cleanup(); // Cleanup.
}

