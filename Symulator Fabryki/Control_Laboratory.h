#pragma once

#include <string>

#include "Building.h"

class Control_Laboratory : public Building
{

protected:

	static char Icon;
	static std::string Name;

public:

	static int Cost;

	Control_Laboratory(int, int);
	~Control_Laboratory();

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
