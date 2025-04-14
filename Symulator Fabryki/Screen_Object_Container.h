#pragma once

#include <vector>


#include "Building.h"


class Screen_Object_Container
{

private:

	std::vector<Building*> Buildings;

public:

	Screen_Object_Container();
	~Screen_Object_Container();

	void Add_Buildings(Building*);
	void Remove_Buildings();
	std::vector<Building*>& Get_Buildings();
};