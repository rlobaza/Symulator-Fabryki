#pragma once

#include <string>

#include "Building.h"

class Packaging_Area : public Building
{

protected:

	static int Cost;
	static char Icon;
	static std::string Name;

public:

	Packaging_Area(int, int);
	~Packaging_Area();

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