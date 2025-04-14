


#include "Screen_Object_Container.h"
#include "Cursor.h"
#include "Player.h"
#include "sell_Building.h"

void sell_Building(Cursor& c1, Screen_Object_Container& Container, Player& p1)
{
	for (int i = 0; i < Container.Get_Buildings().size(); i++)
	{
		if (Container.Get_Buildings()[i]->Get_PosX() == c1.Get_SelX() && Container.Get_Buildings()[i]->Get_PosY() == c1.Get_SelY())
		{
			p1.Change_Money(2 * Container.Get_Buildings()[i]->Get_Cost() / 3);
			Container.Get_Buildings().erase(Container.Get_Buildings().begin() + i);
			i--;
		}
	}
}