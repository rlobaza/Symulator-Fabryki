#pragma once

#include "Screen_Object.h"

class Sorting_Area : public Screen_Object
{
public:

	Sorting_Area(int, int);
	~Sorting_Area();

	virtual void Simulate();
};