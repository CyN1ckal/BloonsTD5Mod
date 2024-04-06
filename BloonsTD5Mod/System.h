#pragma once
#include "pch.h"

// Main Class Definition
class System
{
public:

    uintptr_t MasterObjectListOffset = 0x009FABE0;

    uintptr_t BloonsBaseAddress;
    uintptr_t MonkeyMoneyAddress;
    MasterObjectList* MasterList = nullptr;
    CoreObjectList* CoreList = nullptr;
    MonkeyInfo* CurrentMonkeyInfo = nullptr;

    int DesiredXP = 100000;
    int DesiredRank = 50;
    int DesiredMonkeyMoney = 1000;

    bool GetBloonsInfo();

    bool Keybinds();

    bool AddMoney(double amount);

    bool AddLives(int amount);

    bool MainLoop();

};