#include "pch.h"

bool MyConsole::AllocateConsole()
{
    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);
    g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("Console Allocated.\n");
    return 1;
}

bool MyConsole::EjectConsole()
{
    fclose(f);
    FreeConsole();

    return 1;
}