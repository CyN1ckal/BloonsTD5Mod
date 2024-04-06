#pragma once
#include "pch.h"

class MyWindowClass
{
public:
	bool RegisterMyWindow();
	bool CreateMyWindow();
	bool InitDirectX();
	bool InitImGUI();
	bool MainLoop();

	LPCWSTR m_applicationName;
	HINSTANCE m_hInstance;
	int screenWidth, screenHeight;
	int posX, posY;

	MSG messages;

	HWND m_hWnd;
};