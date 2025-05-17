#include <iostream>
#include <thread>
#include <semaphore>

#include "User_Input_Keys.h"
#include "Screen.h"
#include "Cursor.h"
#include "Screen_Object.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"
#include "Production_Hall.h"
#include "Loading_Ramp.h"
#include "Road.h"
#include "Packaging_Area.h"
#include "Warehouse.h"
#include "Player.h"
#include "check_If_Busy.h"
#include "check_If_Road.h"
#include "sell_Building.h"
#include "lvl_Up.h"

#include "Clock.h"
#include "framerate.h"

#include "Menu.h"
#include "single_Sound.h"

#include "Worker.h"
#include "find_Route.h"

#include "Task.h"
#include "Task_Container.h"


void user_Input_Keys(Screen& s1, Cursor& c1, char& Input, bool& Gameover, Player& p1, Building_Container& Buildings, Worker_Container& Workers, Road_Container& Roads, bool& In_Menu, Menu& menu_1)
{

	Clock clk(framerate());

	while (Gameover == false)
	{

		clk.Set_Start_Time();

		//////////////////////////////////////////////////////////////////////////////////////

		if (In_Menu == true)
		{

			if (Input == 'w')
			{
				menu_1.Selected_Button_Up();
			}

			if (Input == 's')
			{
				menu_1.Selected_Button_Down();
			}

			if (Input == 'e')
			{
				menu_1.Get_Selected_Button()->Do(Gameover, In_Menu);
				Input = ' ';
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////

		if (In_Menu == false)
		{

			if (Input == 'q')
			{
				In_Menu = true;
				single_Sound("Sounds/MENU");
			}

			if (Input == 'w')
			{
				c1.CursorMoveUp();
			}

			if (Input == 's')
			{
				c1.CursorMoveDown();
			}

			if (Input == 'a')
			{
				c1.CursorMoveLeft();
			}

			if (Input == 'd')
			{
				c1.CursorMoveRight();
			}

			if (Input == 'e')
			{
				if (c1.Get_Is_Locked() == false)
				{
					c1.Select();

					single_Sound("Sounds/ON");
				}
				else
				{
					c1.Unselect();

					single_Sound("Sounds/OFF");
				}

			}

			if (Input == '1' && c1.Get_Is_Locked() == true)
			{

			}

			if (Input == '2' && c1.Get_Is_Locked() == true)
			{
				if (check_If_Busy(c1, Buildings) == false)
				{
					Loading_Ramp* building = new Loading_Ramp(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost()); 
						Buildings.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
					else
					{
						single_Sound("Sounds/OFF");
					}
				}
				else
				{
					single_Sound("Sounds/OFF");
				}
			}

			if (Input == '3' && c1.Get_Is_Locked() == true)
			{

			}

			if (Input == '4' && c1.Get_Is_Locked() == true) //Production Hall
			{
				if (check_If_Busy(c1, Buildings) == false)
				{
					Production_Hall* building = new Production_Hall(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Buildings.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
					else
					{
						single_Sound("Sounds/OFF");
					}
				}
				else
				{
					single_Sound("Sounds/OFF");
				}
			}

			if (Input == '5' && c1.Get_Is_Locked() == true) //Road
			{
				if (check_If_Busy(c1, Buildings) == false)
				{
					Road* building = new Road(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Buildings.Add_Buildings(building);
						Roads.Add_Roads(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
					else
					{
						single_Sound("Sounds/OFF");
					}
				}
				else
				{
					single_Sound("Sounds/OFF");
				}
			}

			if (Input == '6' && c1.Get_Is_Locked() == true) //Sorting_Area
			{
				if (check_If_Busy(c1, Buildings) == false)
				{
					Packaging_Area* building = new Packaging_Area(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Buildings.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
					else
					{
						single_Sound("Sounds/OFF");
					}
				}
				else
				{
					single_Sound("Sounds/OFF");
				}
			}

			if (Input == '7' && c1.Get_Is_Locked() == true)
			{

			}

			if (Input == '8' && c1.Get_Is_Locked() == true) //Warehouse
			{
				if (check_If_Busy(c1, Buildings) == false)
				{
					Warehouse* building = new Warehouse(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Buildings.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
					else
					{
						single_Sound("Sounds/OFF");
					}
				}
				else
				{
					single_Sound("Sounds/OFF");
				}
			}

			if (Input == '+' && c1.Get_Is_Locked() == true) //Worker +
			{
				std::lock_guard<std::recursive_mutex> lock(Workers.Get_Mutex());

				if (check_If_Road(c1.Get_SelX(), c1.Get_SelY(), Buildings) == true)
				{
					Worker* worker = new Worker(c1.Get_SelX(), c1.Get_SelY(), Roads, Buildings);
					Workers.Add_Workers(worker);
					c1.Unselect();
				}
				else
				{
					single_Sound("Sounds/OFF");
				}
			}

			if (Input == '-') //Worker -
			{
				std::lock_guard<std::recursive_mutex> lock(Workers.Get_Mutex());

				if (Workers.Get_Workers().Get_Size() > 0)
				{
					Workers.Get_Workers().Erase(Workers.Get_Workers().Get_Size() - 1);
				}
			}

			if (Input == 'x' && c1.Get_Is_Locked() == true) //sell building
			{
				if (check_If_Busy(c1, Buildings) == true)
				{
					sell_Building(c1, Buildings, Roads, p1);
					c1.Unselect();
				}
			}

			if (Input == 'u' && c1.Get_Is_Locked() == true) //upgrade building
			{
				if (check_If_Busy(c1, Buildings) == true)
				{
					if (lvl_Up(c1, Buildings, p1) == true)
					{
						c1.Unselect();
					}
				}
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////

		Input = ' ';

		clk.Set_End_Time();
		clk.Add_Durations();
		clk.Sleep();

	}
}