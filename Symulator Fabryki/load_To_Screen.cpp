#include <iostream>

#include "load_To_Screen.h"

#include "Screen.h"

#include "Screen_Object.h"
#include "Control_Laboratory.h"
#include "Loading_Ramp.h"
#include "Packaging_Area.h"
#include "Production_Hall.h"
#include "Road.h"
#include "Sorting_Area.h"
#include "Staff_Welfare_Area.h"
#include "Warehouse.h"

#include "Screen_Object_Container.h"


void load_To_Screen(Screen& s1, Screen_Object_Container& Container)
{
	for (int i = 0; i < Container.Get_Control_Laboratories().size(); i++)
	{
		s1.Input(Container.Get_Control_Laboratories()[i].PosX, Container.Get_Control_Laboratories()[i].PosY, Container.Get_Control_Laboratories()[i].Icon);
	}

	for (int i = 0; i < Container.Get_Loading_Ramps().size(); i++)
	{
		s1.Input(Container.Get_Loading_Ramps()[i].PosX, Container.Get_Loading_Ramps()[i].PosY, Container.Get_Loading_Ramps()[i].Icon);
	}

	for (int i = 0; i < Container.Get_Packaging_Areas().size(); i++)
	{
		s1.Input(Container.Get_Packaging_Areas()[i].PosX, Container.Get_Packaging_Areas()[i].PosY, Container.Get_Packaging_Areas()[i].Icon);
	}

	for (int i = 0; i < Container.Get_Production_Halls().size(); i++)
	{
		s1.Input(Container.Get_Production_Halls()[i].PosX, Container.Get_Production_Halls()[i].PosY, Container.Get_Production_Halls()[i].Icon);
	}

	for (int i = 0; i < Container.Get_Roads().size(); i++)
	{
		s1.Input(Container.Get_Roads()[i].PosX, Container.Get_Roads()[i].PosY, Container.Get_Roads()[i].Icon);
	}

	for (int i = 0; i < Container.Get_Sorting_Areas().size(); i++)
	{
		s1.Input(Container.Get_Sorting_Areas()[i].PosX, Container.Get_Sorting_Areas()[i].PosY, Container.Get_Sorting_Areas()[i].Icon);
	}

	for (int i = 0; i < Container.Get_Staff_Welfare_Areas().size(); i++)
	{
		s1.Input(Container.Get_Staff_Welfare_Areas()[i].PosX, Container.Get_Staff_Welfare_Areas()[i].PosY, Container.Get_Staff_Welfare_Areas()[i].Icon);
	}

	for (int i = 0; i < Container.Get_Warehouses().size(); i++)
	{
		s1.Input(Container.Get_Warehouses()[i].PosX, Container.Get_Warehouses()[i].PosY, Container.Get_Warehouses()[i].Icon);
	}

	for (int i = 0; i < Container.Get_Workers().size(); i++)
	{
		s1.Input(Container.Get_Workers()[i].PosX, Container.Get_Workers()[i].PosY, Container.Get_Workers()[i].Icon);
	}
}