#include <vector>

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





Screen_Object_Container::Screen_Object_Container()
{

}

Screen_Object_Container::~Screen_Object_Container()
{

}

void Screen_Object_Container::Add_Control_Laboratories(Control_Laboratory cl1)
{
	Control_Laboratories.push_back(cl1);
}

void Screen_Object_Container::Add_Loading_Ramps(Loading_Ramp lr1)
{
	Loading_Ramps.push_back(lr1);
}

void Screen_Object_Container::Add_Packaging_Areas(Packaging_Area pa1)
{
	Packaging_Areas.push_back(pa1);
}

void Screen_Object_Container::Add_Production_Halls(Production_Hall ph1)
{
	Production_Halls.push_back(ph1);
}

void Screen_Object_Container::Add_Roads(Road r1)
{
	Roads.push_back(r1);
}

void Screen_Object_Container::Add_Sorting_Areas(Sorting_Area sa1)
{
	Sorting_Areas.push_back(sa1);
}

void Screen_Object_Container::Add_Staff_Welfare_Areas(Staff_Welfare_Area swa1)
{
	Staff_Welfare_Areas.push_back(swa1);
}

void Screen_Object_Container::Add_Warehouses(Warehouse w1)
{
	Warehouses.push_back(w1);
}

void Screen_Object_Container::Remove_Control_Laboratories(int, int)
{

}

void Screen_Object_Container::Remove_Loading_Ramps(int, int)
{

}

void Screen_Object_Container::Remove_Packaging_Areas(int, int)
{

}

void Screen_Object_Container::Remove_Production_Halls(int, int)
{

}

void Screen_Object_Container::Remove_Roads(int, int)
{

}

void Screen_Object_Container::Remove_Sorting_Areas(int, int)
{

}

void Screen_Object_Container::Remove_Staff_Welfare_Areas(int, int)
{

}

void Screen_Object_Container::Remove_Warehouses(int, int)
{

}

std::vector<Control_Laboratory>& Screen_Object_Container::Get_Control_Laboratories()
{
	return Control_Laboratories;
}

std::vector<Loading_Ramp>& Screen_Object_Container::Get_Loading_Ramps()
{
	return Loading_Ramps;
}

std::vector<Packaging_Area>& Screen_Object_Container::Get_Packaging_Areas()
{
	return Packaging_Areas;
}

std::vector<Production_Hall>& Screen_Object_Container::Get_Production_Halls()
{
	return Production_Halls;
}

std::vector<Road>& Screen_Object_Container::Get_Roads()
{
	return Roads;
}

std::vector<Sorting_Area>& Screen_Object_Container::Get_Sorting_Areas()
{
	return Sorting_Areas;
}

std::vector<Staff_Welfare_Area>& Screen_Object_Container::Get_Staff_Welfare_Areas()
{
	return Staff_Welfare_Areas;
}

std::vector<Warehouse>& Screen_Object_Container::Get_Warehouses()
{
	return Warehouses;
}
