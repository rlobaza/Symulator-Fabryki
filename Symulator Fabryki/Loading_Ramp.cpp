
#include <string>

#include "Loading_Ramp.h"
#include "Building.h"

int Loading_Ramp::Cost = 100;

char Loading_Ramp::Icon = 'R';

std::string Loading_Ramp::Name = "Loading_Ramp";

Loading_Ramp::Loading_Ramp(int x, int y, Player& p) : p1(p)
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

std::string Loading_Ramp::Get_Name()
{
	return Name;
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

	str = str + "Rampa Za³adunkowa " + std::to_string(i + 1) + '\n';
	str = str + "Lvl: " + std::to_string(Get_Lvl()) + '\n';

	str = str + '\n';

	str = str + "Materia³y: " + std::to_string(Get_Materials_Storage_Used()) + " / " + std::to_string(Get_Materials_Storage()) + '\n';
	str = str + "Zapakowane produkty: " + std::to_string(Get_Packed_Products_Storage_Used()) + " / " + std::to_string(Get_Packed_Products_Storage()) + '\n';

	str = str + '\n';

	str = str + "u -> Ulepsz: -" + std::to_string(Get_Cost() * (Get_Lvl() + 1)) + " PLN" + '\n';
	str = str + "x -> Sprzedaj: +" + std::to_string(2 * Get_Cost() * Get_Lvl() / 3) + " PLN" + '\n';

	str = str + "\n\n\n\n";

	return str;
}

char Loading_Ramp::Get_Icon()
{
	return Icon;
}

void Loading_Ramp::Simulate()
{

	for (int i = 0; i < Lvl; i++)
	{
		if (Materials_Storage - Materials_Storage_Used >= 1)
		{
			Materials_Storage_Used += 1;
		}

		if (Packed_Products_Storage_Used > 0)
		{
			Packed_Products_Storage_Used = Packed_Products_Storage_Used - 1;
			p1.Change_Money(p1.Get_Packed_Products_Price());
		}
	}

}

int Loading_Ramp::Get_Cost()
{
	return Cost;
}

void Loading_Ramp::Check_If_Ready()
{
	if (Materials_Storage_Used > 0)
	{
		Is_Ready = true;
	}
	else
	{
		Is_Ready = false;
	}
}