#include <iostream>

#include "load_To_Screen.h"

#include "Screen.h"

#include "Screen_Object.h"
#include "Building.h"
#include "Screen_Object_Container.h"


void load_To_Screen(Screen& s1, Screen_Object_Container& Container)
{
	for (int i = 0; i < Container.Get_Buildings().size(); i++)
	{
		s1.Input(Container.Get_Buildings()[i]->Get_PosX(), Container.Get_Buildings()[i]->Get_PosY(), Container.Get_Buildings()[i]->Get_Icon());
	}
}