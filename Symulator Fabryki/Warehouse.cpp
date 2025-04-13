

#include "Warehouse.h"
#include "Screen_Object.h"

int Warehouse::Cost = 100;

char Warehouse::Icon = 'M';

Warehouse::Warehouse(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Warehouse::~Warehouse()
{

}

int Warehouse::Get_Cost()
{
	return Cost;
}

void Warehouse::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Warehouse::Calculate_Storage()
{
	All_Storage = Lvl * 1000;

	Materials_Storage = 35 * All_Storage / 100;
	Sorted_Materials_Storage = 35 * All_Storage / 100;
	Ready_Products_Storage = 15 * All_Storage / 100;
	Packed_Products_Storage = 15 * All_Storage / 100;

	Materials_Storage_Used = 0;
	Sorted_Materials_Storage_Used = 0;
	Ready_Products_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;
}

char Warehouse::Get_Icon()
{
	return Icon;
}

void Warehouse::Simulate()
{

}