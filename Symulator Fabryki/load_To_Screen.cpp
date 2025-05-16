#include <iostream>
#include <mutex>

#include "load_To_Screen.h"

#include "Screen.h"

#include "Screen_Object.h"
#include "Building_Container.h"
#include "Worker_Container.h"



void load_To_Screen(Screen& s1, Building_Container& Buildings, Worker_Container& Workers)
{

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());
		s1.Input(Buildings.Get_Buildings()[i]->Get_PosX(), Buildings.Get_Buildings()[i]->Get_PosY(), Buildings.Get_Buildings()[i]->Get_Icon());
	}

	for (int i = 0; i < Workers.Get_Workers().Get_Size(); i++)
	{
		std::lock_guard<std::recursive_mutex> lock2(Workers.Get_Mutex());
		s1.Input(Workers.Get_Workers()[i]->Get_PosX(), Workers.Get_Workers()[i]->Get_PosY(), Workers.Get_Workers()[i]->Get_Icon());
	}

	return;
}