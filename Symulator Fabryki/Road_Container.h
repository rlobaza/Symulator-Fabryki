#pragma once


#include <mutex>

#include "Road.h"
#include "Own_List.h"


class Road_Container
{

private:

	Own_List<Road*> Roads;

	std::recursive_mutex mtx;

public:

	Road_Container();
	~Road_Container();

	void Add_Roads(Road*);
	void Remove_Roads(int);
	void Find_Connected();
	void Find_Icon();
	Own_List<Road*>& Get_Roads();
	std::recursive_mutex& Get_Mutex();

};

