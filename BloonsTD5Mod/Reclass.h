#pragma once
#include "pch.h"
// Created with ReClass.NET 1.2 by KN4CK3R

class CoreObjectList
{
public:
	char pad_0000[188]; //0x0000
	class MonkeyStats* PtrToMonkeyStats; //0x00BC
	class MonkeyInfo* PtrToMonkeyInfo; //0x00C0
	char pad_00C4[4]; //0x00C4
	char* PtrToMapName; //0x00C8
	char pad_00CC[8]; //0x00CC
	class Unknown1* PtrToUnknown1; //0x00D4
	char pad_00D8[1512]; //0x00D8
}; //Size: 0x06C0

class MonkeyInfo
{
public:
	char pad_0000[136]; //0x0000
	int32_t Lives; //0x0088
	char pad_008C[4]; //0x008C
	double MonkeyMoney; //0x0090
	int32_t Round; //0x0098
	char pad_009C[364]; //0x009C
}; //Size: 0x0208

class MasterObjectList
{
public:
	class CoreObjectList* PtrToCoreObjectList; //0x0000
	char pad_0004[60]; //0x0004
}; //Size: 0x0040

class Unknown1
{
public:
	char pad_0000[516]; //0x0000
}; //Size: 0x0204

class MonkeyStats
{
public:
	char pad_0000[32]; //0x0000
	int32_t Rank; //0x0020
	char pad_0024[4]; //0x0024
	double XP; //0x0028
	char pad_0030[248]; //0x0030
	uint32_t MonkeyMoney; //0x0128
	char pad_012C[4]; //0x012C
	uint32_t MonkeyTokens; //0x0130
	char pad_0134[148]; //0x0134
}; //Size: 0x01C8

class AbilitiesClass
{
public:
	char pad_0000[1344]; //0x0000
}; //Size: 0x0540