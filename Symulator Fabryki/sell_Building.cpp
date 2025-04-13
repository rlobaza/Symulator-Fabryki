


#include "Screen_Object_Container.h"
#include "Cursor.h"
#include "Player.h"
#include "sell_Building.h"

void sell_Building(Cursor& c1, Screen_Object_Container& Container, Player& p1)
{
	for (int i = 0; i < Container.Get_Control_Laboratories().size(); i++)
	{
		if (Container.Get_Control_Laboratories()[i].Get_PosX() == c1.SelX && Container.Get_Control_Laboratories()[i].Get_PosY() == c1.SelY)
		{
			Container.Get_Control_Laboratories().erase(Container.Get_Control_Laboratories().begin() + i);
			i--;
			p1.ChangeMoney(2 * Control_Laboratory::Get_Cost() / 3);
		}
	}

	for (int i = 0; i < Container.Get_Loading_Ramps().size(); i++)
	{
		if (Container.Get_Loading_Ramps()[i].Get_PosX() == c1.SelX && Container.Get_Loading_Ramps()[i].Get_PosY() == c1.SelY)
		{
			Container.Get_Loading_Ramps().erase(Container.Get_Loading_Ramps().begin() + i);
			i--;
			p1.ChangeMoney(2 * Loading_Ramp::Get_Cost() / 3);
		}
	}

	for (int i = 0; i < Container.Get_Packaging_Areas().size(); i++)
	{
		if (Container.Get_Packaging_Areas()[i].Get_PosX() == c1.SelX && Container.Get_Packaging_Areas()[i].Get_PosY() == c1.SelY)
		{
			Container.Get_Packaging_Areas().erase(Container.Get_Packaging_Areas().begin() + i);
			i--;
			p1.ChangeMoney(2 * Packaging_Area::Get_Cost() / 3);
		}
	}

	for (int i = 0; i < Container.Get_Production_Halls().size(); i++)
	{
		if (Container.Get_Production_Halls()[i].Get_PosX() == c1.SelX && Container.Get_Production_Halls()[i].Get_PosY() == c1.SelY)
		{
			Container.Get_Production_Halls().erase(Container.Get_Production_Halls().begin() + i);
			i--;
			p1.ChangeMoney(2 * Production_Hall::Get_Cost() / 3);
		}
	}

	for (int i = 0; i < Container.Get_Roads().size(); i++)
	{
		if (Container.Get_Roads()[i].Get_PosX() == c1.SelX && Container.Get_Roads()[i].Get_PosY() == c1.SelY)
		{
			Container.Get_Roads().erase(Container.Get_Roads().begin() + i);
			i--;
			p1.ChangeMoney(2 * Road::Get_Cost() / 3);
		}
	}

	for (int i = 0; i < Container.Get_Sorting_Areas().size(); i++)
	{
		if (Container.Get_Sorting_Areas()[i].Get_PosX() == c1.SelX && Container.Get_Sorting_Areas()[i].Get_PosY() == c1.SelY)
		{
			Container.Get_Sorting_Areas().erase(Container.Get_Sorting_Areas().begin() + i);
			i--;
			p1.ChangeMoney(2 * Sorting_Area::Get_Cost() / 3);
		}
	}

	for (int i = 0; i < Container.Get_Staff_Welfare_Areas().size(); i++)
	{
		if (Container.Get_Staff_Welfare_Areas()[i].Get_PosX() == c1.SelX && Container.Get_Staff_Welfare_Areas()[i].Get_PosY() == c1.SelY)
		{
			Container.Get_Staff_Welfare_Areas().erase(Container.Get_Staff_Welfare_Areas().begin() + i);
			i--;
			p1.ChangeMoney(2 * Staff_Welfare_Area::Get_Cost() / 3);
		}
	}

	for (int i = 0; i < Container.Get_Warehouses().size(); i++)
	{
		if (Container.Get_Warehouses()[i].Get_PosX() == c1.SelX && Container.Get_Warehouses()[i].Get_PosY() == c1.SelY)
		{
			Container.Get_Warehouses().erase(Container.Get_Warehouses().begin() + i);
			i--;
			p1.ChangeMoney(2 * Warehouse::Get_Cost() / 3);
		}
	}
}