

#include "Packaging_Area.h"
#include "Building.h"

int Packaging_Area::Cost = 100;

char Packaging_Area::Icon = 'M';

Packaging_Area::Packaging_Area(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Packaging_Area::~Packaging_Area()
{

}

int Packaging_Area::Get_Cost()
{
	return Cost;
}

void Packaging_Area::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Packaging_Area::Calculate_Storage()
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

char Packaging_Area::Get_Icon()
{
	return Icon;
}

void Packaging_Area::Simulate()
{

}