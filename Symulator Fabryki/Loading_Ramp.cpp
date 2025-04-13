

#include "Loading_Ramp.h"
#include "Screen_Object.h"

int Loading_Ramp::Cost = 100;

char Loading_Ramp::Icon = 'R';

Loading_Ramp::Loading_Ramp(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Loading_Ramp::~Loading_Ramp()
{

}

int Loading_Ramp::Get_Cost()
{
	return Cost;
}

void Loading_Ramp::Lvl_Up()
{
	Lvl++;

	Calculate_Storage();
}

void Loading_Ramp::Calculate_Storage()
{
	All_Storage = Lvl * 50;
	Materials_Storage = 6 * All_Storage / 10;
	Packed_Products_Storage = 4 * All_Storage / 10;

	Materials_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;
}

char Loading_Ramp::Get_Icon()
{
	return Icon;
}

void Loading_Ramp::Simulate()
{
	int Delivery = Lvl;

	if (Materials_Storage - Materials_Storage_Used >= Delivery)
	{
		Materials_Storage_Used += Delivery;
	}
}