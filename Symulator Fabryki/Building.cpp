


#include <string>

#include "Building.h"


Building::Building()
{
	Lvl = 1;

	All_Storage = 0;
	Materials_Storage = 0;
	Sorted_Materials_Storage = 0;
	Ready_Products_Storage = 0;
	Packed_Products_Storage = 0;

	Materials_Storage_Used = 0;
	Sorted_Materials_Storage_Used = 0;
	Ready_Products_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;

	Is_Ready = false;
}

Building::~Building()
{

}

int Building::Get_Lvl()
{
	return Lvl;
}

int Building::Get_All_Storage()
{
	return All_Storage;
}

int Building::Get_Materials_Storage()
{
	return Materials_Storage;
}

int Building::Get_Sorted_Materials_Storage()
{
	return Sorted_Materials_Storage;
}

int Building::Get_Ready_Products_Storage()
{
	return Ready_Products_Storage;
}

int Building::Get_Packed_Products_Storage()
{
	return Packed_Products_Storage;
}

int Building::Get_Materials_Storage_Used()
{
	return Materials_Storage_Used;
}

int Building::Get_Sorted_Materials_Storage_Used()
{
	return Sorted_Materials_Storage_Used;
}

int Building::Get_Ready_Products_Storage_Used()
{
	return Ready_Products_Storage_Used;
}

int Building::Get_Packed_Products_Storage_Used()
{
	return Packed_Products_Storage_Used;
}

bool Building::Get_Is_Ready()
{
	return Is_Ready;
}

void Building::Set_Lvl(int param)
{
	Lvl = param;
}

void Building::Set_All_Storage(int param)
{
	All_Storage = param;
}

void Building::Set_Materials_Storage(int param)
{
	Materials_Storage = param;
}

void Building::Set_Sorted_Materials_Storage(int param)
{
	Sorted_Materials_Storage = param;
}

void Building::Set_Ready_Products_Storage(int param)
{
	Ready_Products_Storage = param;
}

void Building::Set_Packed_Products_Storage(int param)
{
	Packed_Products_Storage = param;
}

void Building::Set_Materials_Storage_Used(int param)
{
	Materials_Storage_Used = param;
}

void Building::Set_Sorted_Materials_Storage_Used(int param)
{
	Sorted_Materials_Storage_Used = param;
}

void Building::Set_Ready_Products_Storage_Used(int param)
{
	Ready_Products_Storage_Used = param;
}

void Building::Set_Packed_Products_Storage_Used(int param)
{
	Packed_Products_Storage_Used = param;
}

void Building::Set_Is_Ready(bool param)
{
	Is_Ready = param;
}