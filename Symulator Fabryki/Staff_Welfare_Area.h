#pragma once

#pragma once

#include "Screen_Object.h"

class Staff_Welfare_Area : public Screen_Object
{
public:

	Staff_Welfare_Area(int, int);
	~Staff_Welfare_Area();

	virtual void Simulate();
};