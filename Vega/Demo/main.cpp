#include "../Helpers/Debug.h"
#include "../Helpers/Instance.h"
#include "../Core/Window.h"
#include "../Loader/Loader.h"
#include "../Scene/Actors/Camera.h"

using namespace Vega;

int main()
{
	Helpers::Instance::Setup(); // Setup.

	Core::Window _window("Vega Engine", 800, 600); // New window.
	Core::Window* window = &_window;

	const auto data = Loader::LoadObjectFile(L"Assets/Objects/craneo.obj"); // Load our file.
	window->PassBuffers(data); // Pass the data into our buffers.

	// Create our camera.
	const auto camera = window->GetScene().GetCameras().AddMember(
		Scene::Actors::Camera((float)window->GetDimensions().first / window->GetDimensions().second)
	);

	camera->SetPos(glm::vec3(5.f, 0.f, 5.f)); // Configure our camera.

	Helpers::Debug::Log(L"Running!"); // Run!

	window->Run();

	Helpers::Instance::Cleanup(); // Cleanup.
}

