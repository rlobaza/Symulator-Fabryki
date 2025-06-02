#include <iostream>
#include <thread>
#include <semaphore>

#include "User_Input_Keys.h"
#include "Screen.h"
#include "Cursor.h"
#include "Screen_Object.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Task_Container.h"
#include "Worker_Container.h"
#include "Staff_Welfare_Area.h"
#include "Production_Hall.h"
#include "Loading_Ramp.h"
#include "Road.h"
#include "Packaging_Area.h"
#include "Sorting_Area.h"
#include "Warehouse.h"
#include "Player.h"
#include "check_If_Busy.h"
#include "check_If_Road.h"
#include "check_If_Worker.h"
#include "sell_Building.h"
#include "lvl_Up.h"

#include "Clock.h"
#include "framerate.h"

#include "Menu.h"
#include "single_Sound.h"

#include "Worker.h"
#include "find_Route.h"

#include "Task.h"
#include "Control_Laboratory.h"
#include "add_Score.h"
#include "Own_List.h"


void user_Input_Keys(Screen& s1, Cursor& c1, char& Input, bool& Gameover, Player& p1, Building_Container& Buildings, Worker_Container& Workers, Road_Container& Roads, Task_Container& Tasks, bool& In_Menu, Menu& menu_1, bool& In_Leaderboard, Own_List<Score*>& Leaderboard)
{

	Clock clk(framerate());

	while (Gameover == false)
	{

		clk.Set_Start_Time();

		//////////////////////////////////////////////////////////////////////////////////////

		if (In_Menu == true && In_Leaderboard == false)
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
				menu_1.Get_Selected_Button()->Do(Gameover, In_Menu, In_Leaderboard);
				if (menu_1.Get_Selected_Button()->Get_Name() == "Nowa Gra")
				{
					menu_1.Get_Selected_Button()->Set_Name("Kontynuuj");
					menu_1.Get_Buttons()[2]->Set_Name("Zapisz Wynik i WyjdŸ");
				}
				if (menu_1.Get_Selected_Button()->Get_Name() == "Zapisz Wynik i WyjdŸ")
				{
					add_Score(Leaderboard, p1);
				}
				Input = ' ';
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////

		if (In_Menu == true && In_Leaderboard == true)
		{

			if (Input == 'q')
			{
				In_Leaderboard = false;
				single_Sound("Sounds/MENU");
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

			if (Input == '1' && c1.Get_Is_Locked() == true) //Control_Laboratory
			{
				if (check_If_Busy(c1, Buildings) == false)
				{
					Control_Laboratory* building = new Control_Laboratory(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Buildings.Add_Buildings(building);
						p1.Calculate_Packed_Products_Price();
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

			if (Input == '2' && c1.Get_Is_Locked() == true)
			{
				if (check_If_Busy(c1, Buildings) == false)
				{
					Loading_Ramp* building = new Loading_Ramp(c1.Get_SelX(), c1.Get_SelY(), p1);
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

			if (Input == '3' && c1.Get_Is_Locked() == true) //Packaging_Area
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
					Sorting_Area* building = new Sorting_Area(c1.Get_SelX(), c1.Get_SelY());
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

			if (Input == '7' && c1.Get_Is_Locked() == true) //Staff_Welfare_Area
			{
				if (check_If_Busy(c1, Buildings) == false)
				{
					Staff_Welfare_Area* building = new Staff_Welfare_Area(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Buildings.Add_Buildings(building);
						p1.Calculate_Max_Workers();
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

				if (check_If_Road(c1.Get_SelX(), c1.Get_SelY(), Buildings) == true && p1.Get_Max_Workers() > Workers.Get_Workers().Get_Size())
				{
					Worker* worker = new Worker(c1.Get_SelX(), c1.Get_SelY(), Roads, Buildings, Tasks);
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
				std::scoped_lock lock(Workers.Get_Mutex(), Tasks.Get_Mutex());

				if (Workers.Get_Workers().Get_Size() > 0)
				{
					if (Workers.Get_Workers()[Workers.Get_Workers().Get_Size() - 1]->Get_Current_Task() != nullptr)
					{
						for (int i = 0; i < Tasks.Get_Tasks().Get_Size(); i++)
						{
							if (Workers.Get_Workers()[Workers.Get_Workers().Get_Size() - 1]->Get_Current_Task() == Tasks.Get_Tasks()[i])
							{
								delete Tasks.Get_Tasks()[i];
								Tasks.Get_Tasks().Erase(i);
							}
						}
					}
					Workers.Get_Workers().Erase(Workers.Get_Workers().Get_Size() - 1);
				}
			}

			if (Input == 'x' && c1.Get_Is_Locked() == true) //sell building
			{
				if (check_If_Busy(c1, Buildings) == true)
				{
					if (check_If_Worker(c1.Get_SelX(), c1.Get_SelY(), Workers) == false)
					{
						sell_Building(c1, Buildings, Roads, Tasks, p1);
						p1.Calculate_Max_Workers();
						p1.Calculate_Packed_Products_Price();
						c1.Unselect();
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

			if (Input == 'u' && c1.Get_Is_Locked() == true) //upgrade building
			{
				if (check_If_Busy(c1, Buildings) == true)
				{
					if (lvl_Up(c1, Buildings, p1) == true)
					{
						p1.Calculate_Max_Workers();
						p1.Calculate_Packed_Products_Price();
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