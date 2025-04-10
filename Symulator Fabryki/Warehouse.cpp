

#include "Warehouse.h"
#include "Screen_Object.h"

int Warehouse::Cost = 100;

Warehouse::Warehouse(int PosX, int PosY) : Screen_Object(PosX, PosY, 'W')
{
	Lvl = 1;

	All_Storage = Lvl * 1000;

	Materials_Storage = 0.35 * All_Storage;
	Sorted_Materials_Storage = 0.35 * All_Storage;
	Ready_Products_Storage = 0.15 * All_Storage;
	Packed_Products_Storage = 0.15 * All_Storage;

	Materials_Storage_Used = 0;
	Sorted_Materials_Storage_Used = 0;
	Ready_Products_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;
}

Warehouse::~Warehouse()
{

}

int Warehouse::Get_Cost()
{
	return Cost;
}

int Warehouse::Get_All_Storage()
{
	return All_Storage;
}

int Warehouse::Get_Materials_Storage()
{
	return Materials_Storage;
}

int Warehouse::Get_Sorted_Materials_Storage()
{
	return Sorted_Materials_Storage;
}

int Warehouse::Get_Ready_Products_Storage()
{
	return Ready_Products_Storage;
}

int Warehouse::Get_Packed_Products_Storage()
{
	return Packed_Products_Storage;
}

int Warehouse::Get_Materials_Storage_Used()
{
	return Materials_Storage_Used;
}

int Warehouse::Get_Sorted_Materials_Storage_Used()
{
	return Sorted_Materials_Storage_Used;
}

int Warehouse::Get_Ready_Products_Storage_Used()
{
	return Ready_Products_Storage_Used;
}

int Warehouse::Get_Packed_Products_Storage_Used()
{
	return Packed_Products_Storage_Used;
}