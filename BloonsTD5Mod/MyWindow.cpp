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

bool MyWindowClass::RegisterMyWindow()
{
	m_applicationName = L"Test Name";

	m_hInstance = GetModuleHandle(NULL);
	WNDCLASSEX wc = { 0 }; 
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MyWindowProc;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);
	if (!RegisterClassEx(&wc))
		printf("Error Registering Window Class!\n");

	return 1;
}

bool MyWindowClass::CreateMyWindow()
{
	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
	printf("Screent Width: %d\nScreen Height: %d\n", screenWidth, screenHeight);

	posX = screenWidth / 2;
	posY = screenHeight / 2;
	printf("posX: %d\nposY: %d\n", posX, posY);

	m_hWnd = CreateWindowEx(WS_EX_LAYERED, m_applicationName, m_applicationName,
		WS_BORDER,
		posX, posY, screenWidth, screenHeight, NULL, NULL, m_hInstance, NULL);
	
	if (!m_hWnd)
	{
		printf("Error!\n");
		printf("%d", m_hWnd);
		printf("Last Error Code: %lu\n", GetLastError());
	}

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(m_hWnd, SW_SHOW);
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);

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
