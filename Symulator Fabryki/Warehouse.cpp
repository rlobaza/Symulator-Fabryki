
#include <string>

#include "Warehouse.h"
#include "Screen_Object.h"

int Warehouse::Cost = 100;

char Warehouse::Icon = 'M';

Warehouse::Warehouse(int x, int y)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);

	Materials_Storage_Used = 0;
	Sorted_Materials_Storage_Used = 0;
	Ready_Products_Storage_Used = 0;
	Packed_Products_Storage_Used = 0;
}

Warehouse::~Warehouse()
{

}

void Warehouse::Lvl_Up()
{
	Lvl++;
	
	this->Calculate_Storage();
}

void Warehouse::Calculate_Storage()
{
	All_Storage = Lvl * 1000;

	Materials_Storage = 35 * All_Storage / 100;
	Sorted_Materials_Storage = 35 * All_Storage / 100;
	Ready_Products_Storage = 15 * All_Storage / 100;
	Packed_Products_Storage = 15 * All_Storage / 100;
}

std::string Warehouse::Stats_String(int i)
{
	std::string str = "";

	str = str + "Magazyn " + std::to_string(i + 1) + '\n';
	str = str + "Lvl: " + std::to_string(Get_Lvl()) + '\n';
	str = str + "Materialy: " + std::to_string(Get_Materials_Storage_Used()) + " / " + std::to_string(Get_Materials_Storage()) + '\n';
	str = str + "Posortowane materialy: " + std::to_string(Get_Sorted_Materials_Storage_Used()) + " / " + std::to_string(Get_Sorted_Materials_Storage()) + '\n';
	str = str + "Gotowe produkty: " + std::to_string(Get_Ready_Products_Storage_Used()) + " / " + std::to_string(Get_Ready_Products_Storage()) + '\n';
	str = str + "Zapakowane produkty: " + std::to_string(Get_Packed_Products_Storage_Used()) + " / " + std::to_string(Get_Packed_Products_Storage()) + '\n';

	str = str + '\n';

	return str;
}

char Warehouse::Get_Icon()
{
	return Icon;
}

void Warehouse::Simulate()
{

}

int Warehouse::Get_Cost()
{
	return Cost;
}