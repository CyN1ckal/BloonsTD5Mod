#pragma once
#include "pch.h"

// Main Class Definition
class System
{
public:

    uintptr_t MasterObjectListOffset = 0x009FABE0;

    uintptr_t BloonsBaseAddress;
    uintptr_t MonkeyMoneyAddress;
    HANDLE hConsole;
    FILE* f;
    MasterObjectList* MasterList = nullptr;
    CoreObjectList* CoreList = nullptr;
    MonkeyInfo* CurrentMonkeyInfo = nullptr;

    bool AllocateConsole();

    bool GetBloonsInfo();

    bool Keybinds();

    bool Eject();

    bool AddMoney(double amount);

    bool AddLives(int amount);

    bool MainLoop();

};