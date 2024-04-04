// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// Global Variables
HMODULE g_hModule = 0;
uintptr_t MasterObjectListOffset = 0x009FABE0;

// Main Class Definition
class System
{
public:

    uintptr_t BloonsBaseAddress;
    uintptr_t MonkeyMoneyAddress;
    HANDLE hConsole;
    FILE* f;
    MasterObjectList* MasterList = nullptr;
    CoreObjectList* CoreList = nullptr;
    MonkeyInfo* CurrentMonkeyInfo = nullptr;

    bool AllocateConsole()
    {
        AllocConsole();
        freopen_s(&f, "CONOUT$", "w", stdout);
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        printf("Console Allocated.\n");
        return 1;
    }

    bool GetBloonsInfo()
    {
        BloonsBaseAddress = (uintptr_t)GetModuleHandle(NULL);
        if (!BloonsBaseAddress)
            return 0;
        printf("Bloons Base Address: %X\n", BloonsBaseAddress);

        MasterList = (MasterObjectList*)(BloonsBaseAddress + MasterObjectListOffset);
        if (!MasterList)
            return 0;
        printf("Master List Address: %X\n", (uintptr_t)MasterList);

        CoreList = MasterList->PtrToCoreObjectList;
        if (!CoreList)
            return 0;
        printf("Core List Address: %X\n", (uintptr_t)CoreList);

        return 1;
    }

    bool Keybinds()
    {
        if (GetAsyncKeyState(VK_END) & 1)
        {
            Eject();
        }
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            AddMoney(1000);
        }
        if (GetAsyncKeyState(VK_DELETE) & 1)
        {
            AddLives(25);
        }
        return 1;
    }

    bool Eject()
    {
        printf("Ejecting.\n");
        fclose(f);
        FreeConsole();
        FreeLibraryAndExitThread(g_hModule, 0);
        return 1;
    }

    bool AddMoney(double amount)
    {
        printf("Adding Money\n");
        CoreList->PtrToMonkeyInfo->MonkeyMoney += (double)1000;
        return 1;
    }

    bool AddLives(int amount)
    {
        printf("Adding Lives\n");
        CoreList->PtrToMonkeyInfo->Lives += amount;
        return 1;
    }

    bool MainLoop()
    {
        while (true)
        {
            Keybinds();
            Sleep(250);
        }
        // Execution will technically never get here.
        return 1;
    }

};

DWORD WINAPI StartingThread(LPVOID lpReserved)
{
    System Main;

    Main.AllocateConsole();

    if (!Main.GetBloonsInfo())
    {
        printf("Something went wrong getting BTD5 info!\n");
        return 1;
    }

    Main.MainLoop();

    // Execution will technically never get here.
    return 1;
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

