#include "pch.h"

LRESULT CALLBACK MyWindowProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
		// Check if the window is being destroyed.
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	// Check if the window is being closed.
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}

	// All other messages pass to the message handler in the system class.
	default:
	{
		return 0;
	}
	}
}

LRESULT CALLBACK DLLWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

bool MyWindowClass::RegisterMyWindow()
{
	WNDCLASSEX wc;
	wc.hInstance = m_hInstance;
	wc.lpszClassName = (LPCWSTR)L"InjectedDLLWindowClass";
	wc.lpszClassName = (LPCWSTR)L"MyClassName";
	wc.lpfnWndProc = DLLWindowProc;
	wc.style = CS_DBLCLKS;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	if (!RegisterClassEx(&wc))
		return 0;

	return 1;
}

bool MyWindowClass::CreateMyWindow()
{
	HWND hwnd = CreateWindowEx(0, L"MyClassName", L"Window Title", WS_EX_PALETTEWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL, m_hInstance, NULL);
	ShowWindow(hwnd, SW_SHOWNORMAL);

	return 1;
}

bool MyWindowClass::InitDirectX()
{
	return 1;
}

bool MyWindowClass::InitImGUI() 
{
	return 1;
}

bool MyWindowClass::MainLoop()
{
	MSG messages;
	if (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	return 1;
}