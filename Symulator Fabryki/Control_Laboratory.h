#pragma once

#include <string>

#include "Building.h"

class Control_Laboratory : public Building
{

protected:

	static int Cost;
	static char Icon;

public:

	Control_Laboratory(int, int);
	~Control_Laboratory();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();
	virtual std::string Stats_String(int);

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
	virtual int Get_Cost();
};
