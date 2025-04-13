#pragma once

#include "Building.h"

class Packaging_Area : public Building
{

protected:

	static int Cost;
	static char Icon;

public:

	Packaging_Area(int, int);
	~Packaging_Area();

	//this:
	static int Get_Cost();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
};