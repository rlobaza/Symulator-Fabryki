#pragma once

#include <string>

#include "Building.h"

class Warehouse : public Building
{

protected:

	static char Icon;
	static std::string Name;

public:

	static int Cost;

	Warehouse(int, int);
	~Warehouse();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();
	virtual std::string Stats_String(int);
	virtual std::string Get_Name();

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
	virtual int Get_Cost();
	virtual void Check_If_Ready();
};