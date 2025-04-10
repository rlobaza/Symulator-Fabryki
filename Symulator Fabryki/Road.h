#pragma once

#include "Screen_Object.h"

class Road : public Screen_Object
{
public:

	static int Cost;

	Road(int, int);
	~Road();
};