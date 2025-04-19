
#include <iostream>
#include <string>
#include <iomanip>

#include "print_All_Objects.h"
#include "Screen_Object_Container.h"



std::string print_All_Objects(Screen_Object_Container& Container)
{
	std::lock_guard<std::recursive_mutex> lock(Container.Get_Mutex());

	std::string str;

	for (int i = 0; i < Container.Get_Buildings().Get_Size(); i++)
	{
		str = str + Container.Get_Buildings()[i]->Stats_String(i);
	}

	return str;
}