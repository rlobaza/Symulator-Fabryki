#include <vector>

#include "Cursor.h"
#include "Screen_Object_Container.h"

bool check_If_Busy(Cursor& c1, Screen_Object_Container& Container)
{
	for (int i = 0; i < Container.Get_Control_Laboratories().size(); i++)
	{
		if (Container.Get_Control_Laboratories()[i].PosX == c1.SelX && Container.Get_Control_Laboratories()[i].PosY == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Loading_Ramps().size(); i++)
	{
		if (Container.Get_Loading_Ramps()[i].PosX == c1.SelX && Container.Get_Loading_Ramps()[i].PosY == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Packaging_Areas().size(); i++)
	{
		if (Container.Get_Packaging_Areas()[i].PosX == c1.SelX && Container.Get_Packaging_Areas()[i].PosY == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Production_Halls().size(); i++)
	{
		if (Container.Get_Production_Halls()[i].PosX == c1.SelX && Container.Get_Production_Halls()[i].PosY == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Roads().size(); i++)
	{
		if (Container.Get_Roads()[i].PosX == c1.SelX && Container.Get_Roads()[i].PosY == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Sorting_Areas().size(); i++)
	{
		if (Container.Get_Sorting_Areas()[i].PosX == c1.SelX && Container.Get_Sorting_Areas()[i].PosY == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Staff_Welfare_Areas().size(); i++)
	{
		if (Container.Get_Staff_Welfare_Areas()[i].PosX == c1.SelX && Container.Get_Staff_Welfare_Areas()[i].PosY == c1.SelY)
		{
			return true;
		}
	}

	for (int i = 0; i < Container.Get_Warehouses().size(); i++)
	{
		if (Container.Get_Warehouses()[i].PosX == c1.SelX && Container.Get_Warehouses()[i].PosY == c1.SelY)
		{
			return true;
		}
	}

	return false;
}