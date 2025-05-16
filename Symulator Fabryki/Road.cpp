
#include <string>

#include "Road.h"
#include "Screen_Object.h"

int Road::Cost = 10;

char Road::Icon = '_';

std::string Road::Name = "Road";

Road::Road(int x, int y) : Is_Visited(false), Distance(9999), Previous(nullptr)
{
	this->Calculate_Storage();
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Road::~Road()
{

}

std::string Road::Get_Name()
{
	return Name;
}

void Road::Set_Is_Visited(bool param)
{
	Is_Visited = param;
}

void Road::Set_Distance(int param)
{
	Distance = param;
}

void Road::Set_Previous(Road* param)
{
	Previous = param;
}

void Road::Set_Is_Added(bool param)
{
	Is_Added = param;
}

bool Road::Get_Is_Visited()
{
	return Is_Visited;
}

Own_List<Road*>& Road::Get_Connected()
{
	return Connected;
}

int Road::Get_Distance()
{
	return Distance;
}

Road* Road::Get_Previous()
{
	return Previous;
}

bool Road::Get_Is_Added()
{
	return Is_Added;
}

void Road::Lvl_Up()
{
	Lvl++;

	this->Calculate_Storage();
}

void Road::Calculate_Storage()
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

std::string Road::Stats_String(int i)
{
	std::string str = "";

	/*str = str + "Droga " + std::to_string(i + 1) + '\n';
	str = str + "ID: " + std::to_string(ID) + '\n';

	str = str + "Polaczenia: " + std::to_string(Connected.Get_Size()) + '\n';

	for (int i = 0; i < Connected.Get_Size(); i++)
	{
		str = str + std::to_string(Connected[i]->ID) + " ";
	}
	str = str + '\n';
	str = str + '\n';*/

	return str;
}

char Road::Get_Icon()
{
	return Icon;
}

void Road::Simulate()
{

}

int Road::Get_Cost()
{
	return Cost;
}

void Road::Check_If_Ready()
{
	Is_Ready = false;
}