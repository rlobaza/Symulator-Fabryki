
#include <string>

#include "Staff_Welfare_Area.h"
#include "Screen_Object.h"

int Staff_Welfare_Area::Cost = 100;

char Staff_Welfare_Area::Icon = 'Z';

std::string Staff_Welfare_Area::Name = "Staff_Welfare_Area";

Staff_Welfare_Area::Staff_Welfare_Area(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Staff_Welfare_Area::~Staff_Welfare_Area()
{

}

std::string Staff_Welfare_Area::Get_Name()
{
	return Name;
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

std::string Staff_Welfare_Area::Stats_String(int i)
{
	std::string str = "";

	str = str + "Zaplecze Socjalne " + std::to_string(i + 1) + '\n';
	str = str + "Lvl: " + std::to_string(Get_Lvl()) + '\n';

	str = str + '\n';

	str = str + "u -> Ulepsz: -" + std::to_string(Get_Cost() * (Get_Lvl() + 1)) + " PLN" + '\n';
	str = str + "x -> Sprzedaj: +" + std::to_string(2 * Get_Cost() * Get_Lvl() / 3) + " PLN" + '\n';

	str = str + "\n\n\n\n\n";

	return str;
}

char Staff_Welfare_Area::Get_Icon()
{
	return Icon;
}

void Staff_Welfare_Area::Simulate()
{

}

int Staff_Welfare_Area::Get_Cost()
{
	return Cost;
}

void Staff_Welfare_Area::Check_If_Ready()
{
	Is_Ready = false;
}