#include "Debug.h"
#include "Instance.h"

#include "Window.h"

using namespace Vega;

int main()
{
	// Setup.
	Helpers::Instance::Setup();

	// New window.
	Core::Window window("Vega Engine", 800, 600);

	// Run!
	Helpers::Debug::Log(L"Running!");

	window.Run();

	// Cleanup.
	Helpers::Instance::Cleanup();
}

