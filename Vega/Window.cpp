#include "Window.h"

using namespace Vega;

Window::PrimitiveWindow Window::PrimitiveWindow::pWindow = Window::PrimitiveWindow();

LPCWSTR Window::PrimitiveWindow::GetName()
{
	return className;
}

HINSTANCE Window::PrimitiveWindow::GetInstance()
{
    return pWindow.hInstance;
}

Window::PrimitiveWindow::PrimitiveWindow() : hInstance(GetModuleHandle(nullptr))
{
	WNDCLASSEX wc = { 0 };

	// Config structure.
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = HandleMessageSetup;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetInstance();
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = GetName();
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);
}

Window::PrimitiveWindow::~PrimitiveWindow()
{
	UnregisterClass(className, GetInstance());
}

Vega::Window::Window(std::wstring name, int width, int height)
{
	RECT wRect;

	wRect.left = 100;
	wRect.right = width + wRect.left;
	wRect.top = 100;
	wRect.bottom = height + wRect.top;

	AdjustWindowRect(&wRect, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

	// Create window & get hWnd.
	hWnd = CreateWindow(
		PrimitiveWindow::GetName(),
		name.c_str(),
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT,
		wRect.right - wRect.left,
		wRect.bottom - wRect.top,
		nullptr,
		nullptr,
		PrimitiveWindow::GetInstance(),
		this
	);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
}

Vega::Window::~Window()
{
	DestroyWindow(hWnd);
}

LRESULT WINAPI Window::HandleMessageSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	/* Once */

	// Non-client create.
	if (msg == WM_NCCREATE)
	{
		// Extract pointer to window class from creation data.
		const CREATESTRUCTW* const create = reinterpret_cast<CREATESTRUCTW*>(lParam);
		Window* const wnd = static_cast<Window*>(create->lpCreateParams);
		// Set Win-API managed user data to store pointer to window class.
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(wnd));
		// Set message procedure to normal (non-setup) handler now that setup is finished.
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Window::HandleMessageThunk));

		// Forward message.
		return wnd->HandleMessage(hWnd, msg, wParam, lParam);
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT WINAPI Window::HandleMessageThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	/* Adapt to different calling convention */

	// Retrieve pointer to window class.
	Window* const wnd = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	// Forward message.
	return wnd->HandleMessage(hWnd, msg, wParam, lParam);
}

LRESULT Window::HandleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		Helpers::Output(L"Quit!", std::wstring(), NAME);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

