#pragma once

#pragma once

#include "Building.h"

class Staff_Welfare_Area : public Building
{

protected:

	static int Cost;
	static char Icon;

public:

	Staff_Welfare_Area(int, int);
	~Staff_Welfare_Area();

	//this:
	static int Get_Cost();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
};