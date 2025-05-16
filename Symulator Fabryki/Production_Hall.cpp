
#include <string>

#include "Production_Hall.h"
#include "Screen_Object.h"

int Production_Hall::Cost = 250;

char Production_Hall::Icon = 'H';

std::string Production_Hall::Name = "Production_Hall";

Production_Hall::Production_Hall(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Production_Hall::~Production_Hall()
{

}

std::string Production_Hall::Get_Name()
{
	return Name;
}

void Production_Hall::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Production_Hall::Calculate_Storage()
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

std::string Production_Hall::Stats_String(int i)
{
	std::string str = "";

	str = str + "Hala Produkcyjna " + std::to_string(i + 1) + '\n';

	str = str + '\n';

	return str;
}

char Production_Hall::Get_Icon()
{
	return Icon;
}

void Production_Hall::Simulate()
{

}

int Production_Hall::Get_Cost()
{
	return Cost;
}

void Production_Hall::Check_If_Ready()
{
	Is_Ready = false;
}