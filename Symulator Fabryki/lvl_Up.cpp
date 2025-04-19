



#include "lvl_Up.h"
#include "Cursor.h"



void lvl_Up(Cursor c1, Screen_Object_Container& Container)
{
	std::lock_guard<std::recursive_mutex> lock(Container.Get_Mutex());

	for (int i = 0; i < Container.Get_Buildings().Get_Size(); i++)
	{
		if (Container.Get_Buildings()[i]->Get_PosX() == c1.Get_PosX() && Container.Get_Buildings()[i]->Get_PosY() == c1.Get_PosY())
		{
			Container.Get_Buildings()[i]->Lvl_Up();
		}
	}
}