#include <vector>

#include "Cursor.h"
#include "Screen_Object_Container.h"

bool check_If_Busy(Cursor& c1, Screen_Object_Container& Container)
{
	for (int i = 0; i < Container.Get_Control_Laboratories().size(); i++)
	{
		if (Container.Get_Control_Laboratories()[i].Get_PosX() == c1.SelX && Container.Get_Control_Laboratories()[i].Get_PosY() == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Loading_Ramps().size(); i++)
	{
		if (Container.Get_Loading_Ramps()[i].Get_PosX() == c1.SelX && Container.Get_Loading_Ramps()[i].Get_PosY() == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Packaging_Areas().size(); i++)
	{
		if (Container.Get_Packaging_Areas()[i].Get_PosX() == c1.SelX && Container.Get_Packaging_Areas()[i].Get_PosY() == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Production_Halls().size(); i++)
	{
		if (Container.Get_Production_Halls()[i].Get_PosX() == c1.SelX && Container.Get_Production_Halls()[i].Get_PosY() == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Roads().size(); i++)
	{
		if (Container.Get_Roads()[i].Get_PosX() == c1.SelX && Container.Get_Roads()[i].Get_PosY() == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Sorting_Areas().size(); i++)
	{
		if (Container.Get_Sorting_Areas()[i].Get_PosX() == c1.SelX && Container.Get_Sorting_Areas()[i].Get_PosY() == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Staff_Welfare_Areas().size(); i++)
	{
		if (Container.Get_Staff_Welfare_Areas()[i].Get_PosX() == c1.SelX && Container.Get_Staff_Welfare_Areas()[i].Get_PosY() == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Warehouses().size(); i++)
	{
		if (Container.Get_Warehouses()[i].Get_PosX() == c1.SelX && Container.Get_Warehouses()[i].Get_PosY() == c1.SelY)
		{
			return true;
		}
	}

	return false;
}