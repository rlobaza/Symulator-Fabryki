#include <iostream>
#include <mutex>

#include "load_To_Screen.h"

#include "Screen.h"

#include "Screen_Object.h"
#include "Building.h"
#include "Screen_Object_Container.h"



void load_To_Screen(Screen& s1, Screen_Object_Container& Container)
{
	std::lock_guard<std::recursive_mutex> lock(Container.Get_Mutex());

	for (int i = 0; i < Container.Get_Buildings().Get_Size(); i++)
	{
		s1.Input(Container.Get_Buildings()[i]->Get_PosX(), Container.Get_Buildings()[i]->Get_PosY(), Container.Get_Buildings()[i]->Get_Icon());
	}

	return;
}