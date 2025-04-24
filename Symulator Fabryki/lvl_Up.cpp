



#include "lvl_Up.h"
#include "Cursor.h"
#include "Player.h"
#include "single_Sound.h"


void lvl_Up(Cursor c1, Screen_Object_Container& Container, Player& p1)
{
	std::lock_guard<std::recursive_mutex> lock(Container.Get_Mutex());

	for (int i = 0; i < Container.Get_Buildings().Get_Size(); i++)
	{
		if (Container.Get_Buildings()[i]->Get_PosX() == c1.Get_PosX() && Container.Get_Buildings()[i]->Get_PosY() == c1.Get_PosY())
		{
			if (Container.Get_Buildings()[i]->Get_Cost() * (Container.Get_Buildings()[i]->Get_Lvl() + 1) <= p1.Get_Money())
			{
				p1.Change_Money(-Container.Get_Buildings()[i]->Get_Cost() * (Container.Get_Buildings()[i]->Get_Lvl() + 1));
				Container.Get_Buildings()[i]->Lvl_Up();
				single_Sound("Sounds/BUILD");
			}
		}
	}
}