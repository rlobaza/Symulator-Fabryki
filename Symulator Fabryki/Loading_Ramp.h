#pragma once

#include "Screen_Object.h"

class Loading_Ramp : public Screen_Object
{
private:

	int Lvl;

	static int Cost;

	int All_Storage;
	int Materials_Storage;
	int Packed_Products_Storage;

	int All_Storage_Used;
	int Materials_Storage_Used;
	int Packed_Products_Storage_Used;


public:

	Loading_Ramp(int, int);
	~Loading_Ramp();

	static int Get_Cost();
	int Get_All_Storage();
	int Get_Materials_Storage();
	int Get_Packed_Products_Storage();
	int Get_All_Storage_Used();
	int Get_Materials_Storage_Used();
	int Get_Packed_Products_Storage_Used();

	virtual void Simulate();
};