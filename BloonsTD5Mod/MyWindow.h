#pragma once
#include "pch.h"

class MyWindowClass
{
public:
	bool RegisterMyWindow();
	bool CreateMyWindow();
	bool InitDirectX();
	bool InitImGUI();

	LPCWSTR m_applicationName;
	HINSTANCE m_hInstance;
	int screenWidth, screenHeight;
	int posX, posY;

	HWND m_hWnd;
};