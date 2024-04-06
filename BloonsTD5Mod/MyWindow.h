#pragma once
#include "pch.h"

class MyWindowClass
{
public:
	bool RegisterMyWindow();
	bool CreateMyWindow();
	bool InitDirectX();
	bool CleanDirectX();
	bool InitImGUI();
	bool Frame();

	LPCWSTR m_applicationName;
	HINSTANCE m_hInstance;
	int screenWidth, screenHeight;
	int posX, posY;

	MSG messages;

	HWND m_hWnd;

	IDXGISwapChain* swapchain;             // the pointer to the swap chain interface
	ID3D11Device* dev;                     // the pointer to our Direct3D device interface
	ID3D11DeviceContext* devcon;           // the pointer to our Direct3D device context
	ID3D11RenderTargetView* backbuffer;    // global declaration

};