#pragma once
#include "Vega.h"
#include "Helpers.h"

#define NAME L"Window"

namespace Vega
{
	class Window
	{
	private:
		// Singleton.
		class PrimitiveWindow
		{
		public:
			static LPCWSTR GetName();
			static HINSTANCE GetInstance();
		private:
			PrimitiveWindow();
			~PrimitiveWindow();

			PrimitiveWindow(const PrimitiveWindow&) = delete;
			PrimitiveWindow& operator = (const PrimitiveWindow&) = delete;

			static constexpr LPCWSTR className = CLASS_NAME;
			static PrimitiveWindow pWindow;

			HINSTANCE hInstance;
		};
	public:
		Window(std::wstring name, int width, int height);
		~Window();

		Window(const Window&) = delete;
		Window& operator = (const Window&) = delete;
	private:
		static LRESULT CALLBACK HandleMessageSetup(
			HWND hWnd,
			UINT msg,
			WPARAM wParam,
			LPARAM lParam
		);
		static LRESULT CALLBACK HandleMessageThunk(
			HWND hWnd,
			UINT msg,
			WPARAM wParam,
			LPARAM lParam
		);

		LRESULT HandleMessage(
			HWND hWnd,
			UINT msg,
			WPARAM wParam,
			LPARAM lParam
		);
	private:
		HWND hWnd;

		int width;
		int height;
	};
}

