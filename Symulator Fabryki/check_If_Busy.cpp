#include <vector>

#include "Cursor.h"
#include "Screen_Object_Container.h"

bool check_If_Busy(Cursor& c1, Screen_Object_Container& Container)
{
	for (int i = 0; i < Container.Get_Buildings().size(); i++)
	{
		if (Container.Get_Buildings()[i]->Get_PosX() == c1.Get_SelX() && Container.Get_Buildings()[i]->Get_PosY() == c1.Get_SelY())
		{
			return true;
		}
	}

	return false;
}