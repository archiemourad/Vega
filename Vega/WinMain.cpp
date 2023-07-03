#include "Vega.h"
#include "Helpers.h"

#include "Window.h"

using namespace Vega;

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	// Basic window.
	Window window(CLASS_NAME, 900, 600);

	// Message pump.
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

