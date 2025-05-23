
#include <string>

#include "Control_Laboratory.h"
#include "Screen_Object.h"

int Control_Laboratory::Cost = 100;

char Control_Laboratory::Icon = 'L';

std::string Control_Laboratory::Name = "Control_Laboratory";

Control_Laboratory::Control_Laboratory(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Control_Laboratory::~Control_Laboratory()
{

}

std::string Control_Laboratory::Get_Name()
{
	return Name;
}

void Control_Laboratory::Lvl_Up()
{
	Lvl++;
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

std::string Control_Laboratory::Stats_String(int i)
{
	std::string str = "";

	str = str + "Laboratorium Kontrolne " + std::to_string(i + 1) + '\n';

	str = str + '\n';

	str = str + "u -> Ulepsz: -" + std::to_string(Get_Cost() * (Get_Lvl() + 1)) + " PLN" + '\n';
	str = str + "x -> Sprzedaj: +" + std::to_string(2 * Get_Cost() * Get_Lvl() / 3) + " PLN" + '\n';

	str = str + "\n\n\n\n\n\n";

	return str;
}

char Control_Laboratory::Get_Icon()
{
	return Icon;
}

void Control_Laboratory::Simulate()
{

}

int Control_Laboratory::Get_Cost()
{
	return Cost;
}

void Control_Laboratory::Check_If_Ready()
{
	Is_Ready = false;
}