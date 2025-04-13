

#include "Sorting_Area.h"
#include "Screen_Object.h"

int Sorting_Area::Cost = 100;

char Sorting_Area::Icon = 'S';

Sorting_Area::Sorting_Area(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Sorting_Area::~Sorting_Area()
{

}

int Sorting_Area::Get_Cost()
{
	return Cost;
}

void Sorting_Area::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Sorting_Area::Calculate_Storage()
{
	All_Storage = 0;

	Materials_Storage = 0;
	Sorted_Materials_Storage = 0;
	Ready_Products_Storage = 0;
	Packed_Products_Storage = 0;

	Materials_Storage_Used = 0;
	Sorted_Materials_Storage_Used = 0;
	Ready_Products_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;
}

char Sorting_Area::Get_Icon()
{
	return Icon;
}

void Sorting_Area::Simulate()
{

}