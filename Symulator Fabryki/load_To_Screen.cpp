#include <iostream>
#include <mutex>

#include "load_To_Screen.h"

#include "Screen.h"

#include "Screen_Object.h"
#include "Building_Container.h"
#include "Worker_Container.h"



void load_To_Screen(Screen& s1, Building_Container& Buildings, Worker_Container& Workers)
{
	std::scoped_lock lock(Buildings.Get_Mutex(), Workers.Get_Mutex());


	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		s1.Input(Buildings.Get_Buildings()[i]->Get_PosX(), Buildings.Get_Buildings()[i]->Get_PosY(), Buildings.Get_Buildings()[i]->Get_Icon());
	}

	for (int i = 0; i < Workers.Get_Workers().Get_Size(); i++)
	{
		s1.Input(Workers.Get_Workers()[i]->Get_PosX(), Workers.Get_Workers()[i]->Get_PosY(), Workers.Get_Workers()[i]->Get_Icon());
	}

	return;
}