#pragma once


#include "Building.h"
#include "Own_List.h"

class Screen_Object_Container
{

private:

	Own_List<Building*> Buildings;

	std::recursive_mutex mtx;

public:

	Screen_Object_Container();
	~Screen_Object_Container();

	void Add_Buildings(Building*);
	void Remove_Buildings();
	Own_List<Building*>& Get_Buildings();
	std::recursive_mutex& Get_Mutex();
	
};