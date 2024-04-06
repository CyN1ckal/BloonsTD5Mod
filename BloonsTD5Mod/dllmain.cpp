// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// Global Variables
HMODULE g_hModule = 0;

DWORD WINAPI StartingThread(LPVOID lpReserved)
{
    MyConsole Console;

    Console.AllocateConsole();

    MyWindowClass MyWindow;

    MyWindow.RegisterMyWindow();

    MyWindow.CreateMyWindow();

    System Main;

    if (!Main.GetBloonsInfo())
    {
        printf("Something went wrong getting BTD5 info!\n");
        return 1;
    }

    while (!GetAsyncKeyState(VK_END))
    {
        MyWindow.MainLoop();

        Main.MainLoop();
    }

    Console.EjectConsole();

    FreeLibraryAndExitThread(g_hModule, 0);

    return 1;
}




//Our new windows proc
LRESULT CALLBACK DLLWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
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

