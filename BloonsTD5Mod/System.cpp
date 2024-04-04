#include "pch.h"

// Forward Declarations
extern HMODULE g_hModule;

// Function Definitions
bool System::GetBloonsInfo()
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

bool System::Keybinds()
{
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

bool System::AddMoney(double amount)
{
    printf("Adding Money\n");
    CoreList->PtrToMonkeyInfo->MonkeyMoney += (double)1000;
    return 1;
}

bool System::AddLives(int amount)
{
    printf("Adding Lives\n");
    CoreList->PtrToMonkeyInfo->Lives += amount;
    return 1;
}

bool System::MainLoop()
{
    Keybinds();

    return 1;
}

