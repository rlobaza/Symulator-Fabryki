

#include <vector>


#include "Building.h"
#include "Screen_Object_Container.h"





Screen_Object_Container::Screen_Object_Container()
{

}

Screen_Object_Container::~Screen_Object_Container()
{

}

void Screen_Object_Container::Add_Buildings(Building* ptr)
{
	Buildings.Push_Back(ptr);
}

void Screen_Object_Container::Remove_Buildings()
{

}

Own_List<Building*>& Screen_Object_Container::Get_Buildings()
{
	return Buildings;
}

std::recursive_mutex& Screen_Object_Container::Get_Mutex()
{
	return mtx;
}