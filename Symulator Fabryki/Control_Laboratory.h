#pragma once

#include "Screen_Object.h"

class Control_Laboratory : public Screen_Object
{

private:

	static int Cost;

public:

	Control_Laboratory(int, int);
	~Control_Laboratory();

	virtual void Move(int, int);
	virtual void Simulate();
	static int Get_Cost();
	virtual void Lvl_Up();
};
