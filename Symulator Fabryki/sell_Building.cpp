


#include "Screen_Object_Container.h"
#include "Cursor.h"
#include "Player.h"
#include "sell_Building.h"
#include "single_Sound.h"

void sell_Building(Cursor& c1, Screen_Object_Container& Container, Player& p1)
{
	std::lock_guard<std::recursive_mutex> lock(Container.Get_Mutex());

	for (int i = 0; i < Container.Get_Buildings().Get_Size(); i++)
	{
		if (Container.Get_Buildings()[i]->Get_PosX() == c1.Get_SelX() && Container.Get_Buildings()[i]->Get_PosY() == c1.Get_SelY())
		{
			p1.Change_Money(2 * Container.Get_Buildings()[i]->Get_Cost() * Container.Get_Buildings()[i]->Get_Lvl() / 3);
			delete Container.Get_Buildings()[i];
			Container.Get_Buildings().Erase(i);
			i--;
			single_Sound("Sounds/COINS");
		}
	}
}