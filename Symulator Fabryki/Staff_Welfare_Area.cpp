

#include "Staff_Welfare_Area.h"
#include "Screen_Object.h"

int Staff_Welfare_Area::Cost = 100;

char Staff_Welfare_Area::Icon = 'Z';

Staff_Welfare_Area::Staff_Welfare_Area(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Staff_Welfare_Area::~Staff_Welfare_Area()
{

}

int Staff_Welfare_Area::Get_Cost()
{
	return Cost;
}

void Staff_Welfare_Area::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Staff_Welfare_Area::Calculate_Storage()
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

char Staff_Welfare_Area::Get_Icon()
{
	return Icon;
}

void Staff_Welfare_Area::Simulate()
{

}