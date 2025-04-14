
#include <string>

#include "Loading_Ramp.h"
#include "Building.h"

int Loading_Ramp::Cost = 100;

char Loading_Ramp::Icon = 'R';

Loading_Ramp::Loading_Ramp(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);

	Materials_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;
}

Loading_Ramp::~Loading_Ramp()
{

}

void Loading_Ramp::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Loading_Ramp::Calculate_Storage()
{
	All_Storage = Lvl * 50;
	Materials_Storage = 6 * All_Storage / 10;
	Packed_Products_Storage = 4 * All_Storage / 10;
}

std::string Loading_Ramp::Stats_String(int i)
{
	std::string str = "";

	str = str + "Rampa Zaladunkowa " + std::to_string(i + 1) + '\n';
	str = str + "Lvl: " + std::to_string(Get_Lvl()) + '\n';
	str = str + "Materialy: " + std::to_string(Get_Materials_Storage_Used()) + " / " + std::to_string(Get_Materials_Storage()) + '\n';
	str = str + "Zapakowane produkty: " + std::to_string(Get_Packed_Products_Storage_Used()) + " / " + std::to_string(Get_Packed_Products_Storage()) + '\n';
	str = str + '\n';

	return str;
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

int Loading_Ramp::Get_Cost()
{
	return Cost;
}