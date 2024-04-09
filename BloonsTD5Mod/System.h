#pragma once
#include "pch.h"

// Main Class Definition
class System
{
public:

    uintptr_t MasterObjectListOffset = 0x009FABE0;
    uintptr_t UpdateSpecialAgentOffset = 0x00343B87;

    uintptr_t BloonsBaseAddress;
    uintptr_t MonkeyMoneyAddress;
    MasterObjectList* MasterList = nullptr;
    CoreObjectList* CoreList = nullptr;
    MonkeyInfo* CurrentMonkeyInfo = nullptr;

    int DesiredXP = 100000;
    int DesiredRank = 50;
    int DesiredMonkeyMoney = 1000;
    int DesiredTokens = 100;
    double AddMoneyAmount = 1000;
    int AddLivesAmount = 50;

    bool InfiniteSpecialAgents = 0;
    bool prevInfiniteSpecialAgents = 0;

    bool GetBloonsInfo();

    bool ToggleInfiniteSpecialAgents(bool status);

    bool Keybinds();

    bool AddMoney(double amount);

    bool AddLives(int amount);

    bool MainLoop();

};