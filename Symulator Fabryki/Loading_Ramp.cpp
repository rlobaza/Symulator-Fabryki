

#include "Loading_Ramp.h"
#include "Screen_Object.h"

int Loading_Ramp::Cost = 200;

Loading_Ramp::Loading_Ramp(int PosX, int PosY) : Screen_Object(PosX, PosY, 'R')
{
	Lvl = 1;

	All_Storage = Lvl * 50;
	Materials_Storage = 0.60 * All_Storage;
	Packed_Products_Storage = 0.40 * All_Storage;

	All_Storage_Used = 0;
	Materials_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;
}

Loading_Ramp::~Loading_Ramp()
{

}

int Loading_Ramp::Get_Cost()
{
	return Cost;
}

int Loading_Ramp::Get_All_Storage()
{
	return All_Storage;
}

int Loading_Ramp::Get_Materials_Storage()
{
	return Materials_Storage;
}

int Loading_Ramp::Get_Packed_Products_Storage()
{
	return Packed_Products_Storage;
}

int Loading_Ramp::Get_All_Storage_Used()
{
	return All_Storage_Used;
}

int Loading_Ramp::Get_Materials_Storage_Used()
{
	return Materials_Storage_Used;
}

int Loading_Ramp::Get_Packed_Products_Storage_Used()
{
	return Packed_Products_Storage_Used;
}

void Loading_Ramp::Simulate()
{
	int Delivery = Lvl;

	if (Materials_Storage - Materials_Storage_Used >= Delivery)
	{
		Materials_Storage_Used += Delivery;
	}
}