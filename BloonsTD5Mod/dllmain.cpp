// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// Global Variables
HMODULE g_hModule = 0;
UINT g_ResizeWidth = 0, g_ResizeHeight = 0;

DWORD WINAPI StartingThread(LPVOID lpReserved)
{
    MyConsole Console;

    Console.AllocateConsole();

    MyWindowClass MyWindow;

    MyWindow.RegisterMyWindow();

    MyWindow.CreateMyWindow();

    MyWindow.InitDirectX();

    MyWindow.InitImGUI();

    System Main;

    if (!Main.GetBloonsInfo())
    {
        printf("Something went wrong getting BTD5 info!\n");
        return 1;
    }

    while (!GetAsyncKeyState(VK_END))
    {
        MyWindow.Frame();

        Main.MainLoop();
    }

    Console.EjectConsole();

    MyWindow.CleanDirectX();

    MyWindow.CleanImGUI();

    FreeLibraryAndExitThread(g_hModule, 0);

    return 1;
}


//Our new windows proc
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK DLLWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hwnd, message, wParam, lParam))
        return true;

    switch (message)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        g_ResizeWidth = (UINT)LOWORD(lParam); // Queue resize
        g_ResizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_COMMAND:
        switch (wParam)
        {

        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    g_hModule = hModule;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(g_hModule);
        CreateThread(nullptr, 0, StartingThread, g_hModule, 0, nullptr);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

