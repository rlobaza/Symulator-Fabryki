
#include <iostream>
#include <string>
#include <iomanip>

#include "print_All_Objects.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"



std::string print_All_Objects(Building_Container& Buildings)
{
	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	std::string str;

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		str = str + Buildings.Get_Buildings()[i]->Stats_String(i);
	}

	return str;
}