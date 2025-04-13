#pragma once

#pragma once

#include "Building.h"

class Warehouse : public Building
{

protected:

	static int Cost;
	static char Icon;

public:

	Warehouse(int, int);
	~Warehouse();

	//this:
	static int Get_Cost();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
};