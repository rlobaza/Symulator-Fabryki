#pragma once

#include <string>

#include "Building.h"
#include "Screen_Object_Container.h"

class Control_Laboratory : public Building
{

protected:

	static int Cost;
	static char Icon;

public:

	Control_Laboratory(int, int);
	~Control_Laboratory();

	//this:
	static int Get_Cost();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();
	virtual std::string Stats_String(Screen_Object_Container&, int);

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
};
