

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
	Buildings.push_back(ptr);
}

void Screen_Object_Container::Remove_Buildings()
{

}

std::vector<Building*>& Screen_Object_Container::Get_Buildings()
{
	return Buildings;
}