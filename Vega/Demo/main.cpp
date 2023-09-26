#include "../Helpers/Debug.h"
#include "../Helpers/Instance.h"
#include "../Core/Window.h"
#include "../Loader/Loader.h"

#include "../Scene/Actors/Camera.h"
#include "../Scene/Actors/Object.h"

using namespace Vega;

int main()
{
	Helpers::Instance::Setup(); // Setup.

	Core::Window _window("Vega Engine", 800, 600); // New window.
	Core::Window* window = &_window;

	// Create/Load/Configure our objects.
	const auto craneo = window->GetScene().GetObjects().AddMember(Scene::Actors::Object());
	const auto craneoData = Loader::LoadObjectFile(L"Assets/Objects/craneo.obj");
	craneo->UpdateBuffers(craneoData);

	const auto floor = window->GetScene().GetObjects().AddMember(Scene::Actors::Object());
	const auto floorData = Loader::LoadObjectFile(L"Assets/Objects/floor.obj");
	floor->UpdateBuffers(floorData);

	floor->SetPos(glm::vec3(0.f, -5.f, 0.f)); // Position floor below craneo.
	floor->SetAngle(45.f); // Rotate floor to face the camera.

	// Create our camera.
	const auto camera = window->GetScene().GetCameras().AddMember(
		Scene::Actors::Camera((float)window->GetDimensions().first / window->GetDimensions().second)
	);

	camera->SetPos(glm::vec3(5.f, 1.f, 5.f)); // Configure our camera.

	Helpers::Debug::Log(L"Running!");

	window->Start(); // Run!

	Helpers::Instance::Cleanup(); // Cleanup.
}

