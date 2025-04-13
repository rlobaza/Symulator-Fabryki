

#include "Control_Laboratory.h"
#include "Screen_Object.h"

int Control_Laboratory::Cost = 100;

char Control_Laboratory::Icon = 'L';

Control_Laboratory::Control_Laboratory(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Control_Laboratory::~Control_Laboratory()
{

}

int Control_Laboratory::Get_Cost()
{
	return Cost;
}

void Control_Laboratory::Lvl_Up()
{

}

void Control_Laboratory::Calculate_Storage()
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

char Control_Laboratory::Get_Icon()
{
	return Icon;
}

void Control_Laboratory::Simulate()
{

}