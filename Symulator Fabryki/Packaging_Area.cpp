
#include <string>

#include "Packaging_Area.h"
#include "Building.h"

int Packaging_Area::Cost = 100;

char Packaging_Area::Icon = 'P';

Packaging_Area::Packaging_Area(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);

	Materials_Storage_Used = 0;
	Sorted_Materials_Storage_Used = 0;
	Ready_Products_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;
}

Packaging_Area::~Packaging_Area()
{

}

void Packaging_Area::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Packaging_Area::Calculate_Storage()
{
	All_Storage = Lvl * 2;

	Materials_Storage = 0;
	Sorted_Materials_Storage = 0;
	Ready_Products_Storage = All_Storage / 2;
	Packed_Products_Storage = All_Storage / 2;
}

std::string Packaging_Area::Stats_String(int i)
{
	std::string str = "";

	str = str + "Strefa Pakowania " + std::to_string(i + 1) + '\n';
	str = str + "Lvl: " + std::to_string(Get_Lvl()) + '\n';
	str = str + "Gotowe produkty: " + std::to_string(Get_Ready_Products_Storage_Used()) + " / " + std::to_string(Get_Ready_Products_Storage()) + '\n';
	str = str + "Zapakowane produkty: " + std::to_string(Get_Packed_Products_Storage_Used()) + " / " + std::to_string(Get_Packed_Products_Storage()) + '\n';

	str = str + '\n';

	return str;
}

char Packaging_Area::Get_Icon()
{
	return Icon;
}

void Packaging_Area::Simulate()
{
	if (Ready_Products_Storage_Used >= 1)
	{
		Ready_Products_Storage_Used = Ready_Products_Storage_Used - 1 * Lvl;
		Packed_Products_Storage_Used = Packed_Products_Storage_Used - 1 * Lvl;
	}
}

int Packaging_Area::Get_Cost()
{
	return Cost;
}

void Packaging_Area::Check_If_Ready()
{
	Is_Ready = false;
}