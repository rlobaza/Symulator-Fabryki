#pragma once

#include "Building.h"

class Sorting_Area : public Building
{

protected:

	static int Cost;
	static char Icon;

public:

	Sorting_Area(int, int);
	~Sorting_Area();

	//this:
	static int Get_Cost();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
};