#pragma once

#pragma once

#include "Screen_Object.h"

class Warehouse : public Screen_Object
{

private:

	int Lvl;

	static int Cost;

	int All_Storage;
	int Materials_Storage;
	int Sorted_Materials_Storage;
	int Ready_Products_Storage;
	int Packed_Products_Storage;

	int Materials_Storage_Used;
	int Sorted_Materials_Storage_Used;
	int Ready_Products_Storage_Used;
	int Packed_Products_Storage_Used;


public:

	Warehouse(int, int);
	~Warehouse();

	static int Get_Cost();
	int Get_All_Storage();
	int Get_Materials_Storage();
	int Get_Sorted_Materials_Storage();
	int Get_Ready_Products_Storage();
	int Get_Packed_Products_Storage();
	int Get_Materials_Storage_Used();
	int Get_Sorted_Materials_Storage_Used();
	int Get_Ready_Products_Storage_Used();
	int Get_Packed_Products_Storage_Used();
};