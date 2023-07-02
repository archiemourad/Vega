#include "Vega.h"
#include "Helpers.h"

#define NAME L"WinMain.cpp"

using namespace Vega;

LRESULT CALLBACK WndProc(
	HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		Helpers::Output(L"Quit!", std::wstring(), NAME);
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	WNDCLASSEX wc = { 0 };

	// Config structure.
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = CLASS_NAME;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	HWND hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		CLASS_NAME,
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200,
		900, 600,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	ShowWindow(hWnd, SW_SHOW);

	// Message pump.
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

