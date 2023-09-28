#include "../Helpers/Debug.h"
#include "../Helpers/Instance.h"
#include "../Core/Window.h"
#include "../Loader/Loader.h"
#include "../Misc/Texture/Texture.h"

#include "../Scene/Actors/Camera.h"
#include "../Scene/Actors/Object.h"

#include <memory>

using namespace Vega;

int main()
{
	Helpers::Instance::Setup(); // Setup.

	// New window.
	std::unique_ptr<Core::Window> window = std::make_unique<Core::Window>("Vega Engine", 800, 600);

	// Create/Load/Configure our objects.
	const auto craneo = window->GetScene().GetObjects().AddMember(Scene::Actors::Object());
	const auto craneoData = Loader::LoadObjectFile(L"Assets/Objects/craneo.obj");
	craneo->UpdateBuffers(craneoData);

	Misc::Texture::Texture craneoTexture;
	craneoTexture.LoadTexture("Assets/Textures/craneo.jpg");

	craneo->SetTexture(craneoTexture);

	const auto floor = window->GetScene().GetObjects().AddMember(Scene::Actors::Object());
	const auto floorData = Loader::LoadObjectFile(L"Assets/Objects/floor.obj");
	floor->UpdateBuffers(floorData);

	Misc::Texture::Texture floorTexture;
	floorTexture.LoadTexture("Assets/Textures/tiles.jpg");

	floor->SetTexture(floorTexture);

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

