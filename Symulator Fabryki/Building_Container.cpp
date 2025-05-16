
#include <mutex>

#include "Building.h"
#include "Building_Container.h"





Building_Container::Building_Container()
{

}

Building_Container::~Building_Container()
{

}

void Building_Container::Add_Buildings(Building* ptr)
{
	std::lock_guard<std::recursive_mutex> lock(mtx);
	Buildings.Push_Back(ptr);
}

void Building_Container::Remove_Buildings()
{

}

Own_List<Building*>& Building_Container::Get_Buildings()
{
	return Buildings;
}

std::recursive_mutex& Building_Container::Get_Mutex()
{
	return mtx;
}