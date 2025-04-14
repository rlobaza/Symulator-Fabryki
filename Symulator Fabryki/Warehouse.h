#pragma once

#include <string>

#include "Building.h"

class Warehouse : public Building
{

protected:

	static int Cost;
	static char Icon;

public:

	Warehouse(int, int);
	~Warehouse();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();
	virtual std::string Stats_String(int);

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
	virtual int Get_Cost();
};