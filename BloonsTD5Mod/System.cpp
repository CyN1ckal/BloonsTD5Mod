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
    CoreList->PtrToMonkeyInfo->MonkeyMoney += (double)amount;
    return 1;
}

bool System::AddLives(int amount)
{
    CoreList->PtrToMonkeyInfo->Lives += amount;
    return 1;
}

bool System::MainLoop()
{

    if (InfiniteSpecialAgents == 1 && prevInfiniteSpecialAgents == 0)
        ToggleInfiniteSpecialAgents(1);
    else if (InfiniteSpecialAgents == 0 && prevInfiniteSpecialAgents == 1)
        ToggleInfiniteSpecialAgents(0);


    Keybinds();


    return 1;
}

bool System::ToggleInfiniteSpecialAgents(bool status)
{
    uintptr_t SpecialAgentUpdateAddress = BloonsBaseAddress + UpdateSpecialAgentOffset;

    DWORD oldProtect;

    VirtualProtect((LPVOID)SpecialAgentUpdateAddress, 3, PAGE_READWRITE, &oldProtect);

    if (status)
    {
        memset((LPVOID)SpecialAgentUpdateAddress, 0x90, 0x3);
        prevInfiniteSpecialAgents = 1;
    }
    else
    {
        BYTE bytes[3] = { 0x89, 0x48, 0x18 };
        memcpy((LPVOID)SpecialAgentUpdateAddress, bytes, 3);
        prevInfiniteSpecialAgents = 0;
    }

    VirtualProtect((LPVOID)SpecialAgentUpdateAddress, 3, oldProtect, &oldProtect);

    return 1;
}

