#pragma once

#include "Building.h"

class Production_Hall : public Building
{

protected:

	static int Cost;
	static char Icon;

public:

	Production_Hall(int, int);
	~Production_Hall();

	//this:
	static int Get_Cost();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
};

