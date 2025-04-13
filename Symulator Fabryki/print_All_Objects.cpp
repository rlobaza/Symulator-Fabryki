
#include <iostream>
#include <string>
#include <iomanip>

#include "print_All_Objects.h"
#include "Screen_Object_Container.h"



std::string print_All_Objects(Screen_Object_Container& Container)
{

	std::string str;

	for (int i = 0; i < Container.Get_Control_Laboratories().size(); i++)
	{
		
	}

	for (int i = 0; i < Container.Get_Loading_Ramps().size(); i++)
	{
		str = str + "Rampa " + std::to_string(i + 1) + '\n';
		str = str + "Materialy: " + std::to_string(Container.Get_Loading_Ramps()[i].Get_Materials_Storage_Used()) + " / " + std::to_string(Container.Get_Loading_Ramps()[i].Get_Materials_Storage()) + '\n';
		str = str + "Zapakowane produkty: " + std::to_string(Container.Get_Loading_Ramps()[i].Get_Packed_Products_Storage_Used()) + " / " + std::to_string(Container.Get_Loading_Ramps()[i].Get_Packed_Products_Storage()) + '\n';
		str = str + '\n';
	}

	for (int i = 0; i < Container.Get_Packaging_Areas().size(); i++)
	{
		
	}

	for (int i = 0; i < Container.Get_Production_Halls().size(); i++)
	{
		
	}

	for (int i = 0; i < Container.Get_Roads().size(); i++)
	{
		
	}

	for (int i = 0; i < Container.Get_Sorting_Areas().size(); i++)
	{
		
	}

	for (int i = 0; i < Container.Get_Staff_Welfare_Areas().size(); i++)
	{
		
	}

	for (int i = 0; i < Container.Get_Warehouses().size(); i++)
	{
		str = str + "Magazyn " + std::to_string(i + 1) + '\n';
		str = str + "Materialy: " + std::to_string(Container.Get_Warehouses()[i].Get_Materials_Storage_Used()) + " / " + std::to_string(Container.Get_Warehouses()[i].Get_Materials_Storage()) + '\n';
		str = str + "Posortowane materialy: " + std::to_string(Container.Get_Warehouses()[i].Get_Sorted_Materials_Storage_Used()) + " / " + std::to_string(Container.Get_Warehouses()[i].Get_Sorted_Materials_Storage()) + '\n';
		str = str + "Gotowe produkty: " + std::to_string(Container.Get_Warehouses()[i].Get_Ready_Products_Storage_Used()) + " / " + std::to_string(Container.Get_Warehouses()[i].Get_Ready_Products_Storage()) + '\n';
		str = str + "Zapakowane produkty: " + std::to_string(Container.Get_Warehouses()[i].Get_Packed_Products_Storage_Used()) + " / " + std::to_string(Container.Get_Warehouses()[i].Get_Packed_Products_Storage()) + '\n';
		str = str + '\n';
	}

	return str;
}