


#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"
#include "Cursor.h"
#include "Player.h"
#include "sell_Building.h"
#include "single_Sound.h"

void sell_Building(Cursor& c1, Building_Container& Buildings, Road_Container& Roads, Player& p1)
{
	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_PosX() == c1.Get_SelX() && Buildings.Get_Buildings()[i]->Get_PosY() == c1.Get_SelY())
		{
			p1.Change_Money(2 * Buildings.Get_Buildings()[i]->Get_Cost() * Buildings.Get_Buildings()[i]->Get_Lvl() / 3);
			Buildings.Get_Buildings().Erase(i);
			i--;
			single_Sound("Sounds/COINS");
		}

	}

	for (int i = 0; i < Roads.Get_Roads().Get_Size(); i++)
	{

		if (Roads.Get_Roads()[i]->Get_PosX() == c1.Get_SelX() && Roads.Get_Roads()[i]->Get_PosY() == c1.Get_SelY())
		{
			delete Roads.Get_Roads()[i];
			Roads.Remove_Roads(i);
			i--;
		}

	}
}