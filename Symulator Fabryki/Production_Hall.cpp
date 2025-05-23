
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
	All_Storage = 2 * Lvl;

	Materials_Storage = 0;
	Sorted_Materials_Storage = All_Storage / 2;
	Ready_Products_Storage = All_Storage / 2;
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
	str = str + "Lvl: " + std::to_string(Get_Lvl()) + '\n';

	str = str + '\n';

	str = str + "Posortowane Materia�y: " + std::to_string(Get_Sorted_Materials_Storage_Used()) + " / " + std::to_string(Get_Sorted_Materials_Storage()) + '\n';
	//str = str + "Zarezerwowane miejsce na Posortowane Materialy: " + std::to_string(Get_Sorted_Materials_Storage_Reserved()) + '\n';
	str = str + "Gotowe Produkty: " + std::to_string(Get_Ready_Products_Storage_Used()) + " / " + std::to_string(Get_Ready_Products_Storage()) + '\n';
	//str = str + "Zarezerwowane miejsce na Gotowe Produkty: " + std::to_string(Get_Ready_Products_Storage_Reserved()) + '\n';

	str = str + '\n';

	str = str + "u -> Ulepsz: -" + std::to_string(Get_Cost() * (Get_Lvl() + 1)) + " PLN" + '\n';
	str = str + "x -> Sprzedaj: +" + std::to_string(2 * Get_Cost() * Get_Lvl() / 3) + " PLN" + '\n';

	str = str + "\n\n\n\n";

	return str;
}

char Production_Hall::Get_Icon()
{
	return Icon;
}

void Production_Hall::Simulate()
{
	for (int i = 0; i < Lvl; i++)
	{
		if (Sorted_Materials_Storage_Used - 1 >= 0)
		{
			if (Ready_Products_Storage >= Ready_Products_Storage_Used + 1)
			{
				Sorted_Materials_Storage_Used = Sorted_Materials_Storage_Used - 1;
				Ready_Products_Storage_Used = Ready_Products_Storage_Used + 1;
			}
		}
	}
}

int Production_Hall::Get_Cost()
{
	return Cost;
}

void Production_Hall::Check_If_Ready()
{
	Is_Ready = false;
}