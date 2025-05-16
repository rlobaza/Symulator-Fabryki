#include <vector>

#include "Cursor.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"

bool check_If_Busy(Cursor& c1, Building_Container& Buildings)
{
	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_PosX() == c1.Get_SelX() && Buildings.Get_Buildings()[i]->Get_PosY() == c1.Get_SelY())
		{
			return true;
		}
	}

	return false;
}