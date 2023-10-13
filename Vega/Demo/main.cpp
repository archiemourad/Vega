#include "../Helpers/Debug.h"
#include "../Helpers/Instance.h"

#include "../Core/Window.h"
#include "../Render/Renderer.h"

#include "../Loader/Loader.h"
#include "../Misc/Texture/Texture.h"

#include "../Scene/Actors/Camera.h"
#include "../Scene/Actors/Object.h"

#include <memory>

using namespace Vega;

void SetupSkybox(std::shared_ptr<Core::Window> window)
{
	const auto skybox = window->GetScene().GetObjects().AddMember(Scene::Actors::Object());
	const auto skyboxData = Loader::LoadObjectFile(L"Assets/Objects/skybox.obj");
	skybox->UpdateBuffers(skyboxData);

	Misc::Texture::Texture skyboxTexture;
	skyboxTexture.LoadTexture("Assets/Textures/sky.jpg");

	skybox->SetTexture(skyboxTexture);

	skybox->SetScale(glm::vec3(90.f, 90.f, 90.f)); // Resize skybox.
}

void SetupCraneo(std::shared_ptr<Core::Window> window)
{
	const auto craneo = window->GetScene().GetObjects().AddMember(Scene::Actors::Object());
	const auto craneoData = Loader::LoadObjectFile(L"Assets/Objects/craneo.obj");
	craneo->UpdateBuffers(craneoData);

	Misc::Texture::Texture craneoTexture;
	craneoTexture.LoadTexture("Assets/Textures/craneo.jpg");

	craneo->SetTexture(craneoTexture);
}

void SetupFloor(std::shared_ptr<Core::Window> window)
{
	const auto floor = window->GetScene().GetObjects().AddMember(Scene::Actors::Object());
	const auto floorData = Loader::LoadObjectFile(L"Assets/Objects/floor.obj");
	floor->UpdateBuffers(floorData);

	Misc::Texture::Texture floorTexture;
	floorTexture.LoadTexture("Assets/Textures/tiles.jpg");

	floor->SetTexture(floorTexture);

	floor->SetPos(glm::vec3(0.f, -5.f, 0.f)); // Position floor below craneo.
	floor->SetAngle(45.f); // Rotate floor to face the camera.
}

int main()
{
	Helpers::Instance::Setup(); // Setup.

	// New window.
	const std::pair<int, int> resolution = Helpers::Debug::User::GetDesktopResolution(); // Get the desktop resolution.
	std::shared_ptr<Core::Window> window = std::make_shared<Core::Window>("Vega Engine", resolution.first / 2, resolution.second / 2);
	// New renderer.
	std::shared_ptr<Render::Renderer> renderer = std::make_shared<Render::Renderer>();

	// Create/Load/Configure our objects.
	SetupSkybox(window);

	SetupCraneo(window);
	SetupFloor(window);

	// Create our camera.
	const auto camera = window->GetScene().GetCameras().AddMember(
		Scene::Actors::Camera((float)window->GetDimensions().first / window->GetDimensions().second)
	);

	camera->SetPos(glm::vec3(5.f, 1.f, 5.f)); // Configure our camera.

	window->Setup(); // Prepare the window for rendering.

	Helpers::Debug::Log(L"Running!");

	// Draw/Render/Logic loop.
	do { renderer->Draw(window); } while (glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window->GetWindow()) == 0);

	window->Cleanup(); // Cleanup after rendering.

	Helpers::Instance::Cleanup(); // Cleanup.
}

