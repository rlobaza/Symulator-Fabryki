

#include "check_If_Road.h"
#include "Building_Container.h"


bool check_If_Road(int x, int y, Building_Container& Buildings)
{

	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_PosX() == x && Buildings.Get_Buildings()[i]->Get_PosY() == y)
		{
			if (Buildings.Get_Buildings()[i]->Get_Name() == "Road")
			{
				return true;
			}
		}
	}

	return false;

}