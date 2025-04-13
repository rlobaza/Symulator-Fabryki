#pragma once

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

class Screen_Object_Container
{

private:
	std::vector<Control_Laboratory> Control_Laboratories;
	std::vector<Loading_Ramp> Loading_Ramps;
	std::vector<Packaging_Area> Packaging_Areas;
	std::vector<Production_Hall> Production_Halls;
	std::vector<Road> Roads;
	std::vector<Sorting_Area> Sorting_Areas;
	std::vector<Staff_Welfare_Area> Staff_Welfare_Areas;
	std::vector<Warehouse> Warehouses;

public:
	Screen_Object_Container();
	~Screen_Object_Container();

	void Add_Control_Laboratories(Control_Laboratory);
	void Add_Loading_Ramps(Loading_Ramp);
	void Add_Packaging_Areas(Packaging_Area);
	void Add_Production_Halls(Production_Hall);
	void Add_Roads(Road);
	void Add_Sorting_Areas(Sorting_Area);
	void Add_Staff_Welfare_Areas(Staff_Welfare_Area);
	void Add_Warehouses(Warehouse);

	void Remove_Control_Laboratories(int, int);
	void Remove_Loading_Ramps(int, int);
	void Remove_Packaging_Areas(int, int);
	void Remove_Production_Halls(int, int);
	void Remove_Roads(int, int);
	void Remove_Sorting_Areas(int, int);
	void Remove_Staff_Welfare_Areas(int, int);
	void Remove_Warehouses(int, int);

	std::vector<Control_Laboratory>& Get_Control_Laboratories();
	std::vector<Loading_Ramp>& Get_Loading_Ramps();
	std::vector<Packaging_Area>& Get_Packaging_Areas();
	std::vector<Production_Hall>& Get_Production_Halls();
	std::vector<Road>& Get_Roads();
	std::vector<Sorting_Area>& Get_Sorting_Areas();
	std::vector<Staff_Welfare_Area>& Get_Staff_Welfare_Areas();
	std::vector<Warehouse>& Get_Warehouses();
};
