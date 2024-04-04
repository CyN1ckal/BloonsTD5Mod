#pragma once
#include "pch.h"

class MyConsole
{
public:
	HANDLE g_hConsole;
	FILE* f;

	bool AllocateConsole();
	bool EjectConsole();
};