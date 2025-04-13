

#include "Road.h"
#include "Screen_Object.h"

int Road::Cost = 10;

char Road::Icon = '°';

Road::Road(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Road::~Road()
{

}

int Road::Get_Cost()
{
	return Cost;
}

void Road::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Road::Calculate_Storage()
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

char Road::Get_Icon()
{
	return Icon;
}

void Road::Simulate()
{

}