



#include "lvl_Up.h"
#include "Cursor.h"
#include "Player.h"
#include "single_Sound.h"

#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"


bool lvl_Up(Cursor c1, Building_Container& Buildings, Player& p1)
{
	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_PosX() == c1.Get_PosX() && Buildings.Get_Buildings()[i]->Get_PosY() == c1.Get_PosY())
		{
			if (Buildings.Get_Buildings()[i]->Get_Cost() * (Buildings.Get_Buildings()[i]->Get_Lvl() + 1) <= p1.Get_Money())
			{
				p1.Change_Money(-Buildings.Get_Buildings()[i]->Get_Cost() * (Buildings.Get_Buildings()[i]->Get_Lvl() + 1));
				Buildings.Get_Buildings()[i]->Lvl_Up();
				single_Sound("Sounds/BUILD");
				return true;
			}
			else
			{
				single_Sound("Sounds/OFF");
				return false;
			}
		}
	}

	return false;
}