#pragma once

#include <mutex>

#include "Building.h"
#include "Own_List.h"

class Building_Container
{

private:

	Own_List<Building*> Buildings;

	std::recursive_mutex mtx;

public:

	Building_Container();
	~Building_Container();

	void Add_Buildings(Building*);
	void Remove_Buildings();
	Own_List<Building*>& Get_Buildings();
	std::recursive_mutex& Get_Mutex();
	
};