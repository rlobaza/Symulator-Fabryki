#include <iostream>
#include <thread>
#include <semaphore>

#include "User_Input_Keys.h"
#include "Screen.h"
#include "Cursor.h"
#include "Screen_Object.h"
#include "Screen_Object_Container.h"
#include "Production_Hall.h"
#include "Loading_Ramp.h"
#include "Road.h"
#include "Packaging_Area.h"
#include "Warehouse.h"
#include "Player.h"
#include "check_If_Busy.h"
#include "sell_Building.h"
#include "lvl_Up.h"

#include "Clock.h"
#include "framerate.h"

#include "Menu.h"
#include "single_Sound.h"


void user_Input_Keys(Screen& s1, Cursor& c1, char& Input, bool& Gameover, Player& p1, Screen_Object_Container& Container, bool& In_Menu, Menu& menu_1)
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
				if (check_If_Busy(c1, Container) == false)
				{
					Loading_Ramp* building = new Loading_Ramp(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Container.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
				}
			}

			if (Input == '3' && c1.Get_Is_Locked() == true)
			{

			}

			if (Input == '4' && c1.Get_Is_Locked() == true) //Production Hall
			{
				if (check_If_Busy(c1, Container) == false)
				{
					Production_Hall* building = new Production_Hall(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Container.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
				}
			}

			if (Input == '5' && c1.Get_Is_Locked() == true) //Road
			{
				if (check_If_Busy(c1, Container) == false)
				{
					Road* building = new Road(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Container.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
				}
			}

			if (Input == '6' && c1.Get_Is_Locked() == true) //Sorting_Area
			{
				if (check_If_Busy(c1, Container) == false)
				{
					Packaging_Area* building = new Packaging_Area(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Container.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
				}
			}

			if (Input == '7' && c1.Get_Is_Locked() == true)
			{

			}

			if (Input == '8' && c1.Get_Is_Locked() == true) //Warehouse
			{
				if (check_If_Busy(c1, Container) == false)
				{
					Warehouse* building = new Warehouse(c1.Get_SelX(), c1.Get_SelY());
					if (p1.Get_Money() >= building->Get_Cost())
					{
						p1.Change_Money(-building->Get_Cost());
						Container.Add_Buildings(building);
						c1.Unselect();
						single_Sound("Sounds/COLLAPSE");
					}
				}
			}

			if (Input == 'x' && c1.Get_Is_Locked() == true)
			{
				if (check_If_Busy(c1, Container) == true)
				{
					sell_Building(c1, Container, p1);
					c1.Unselect();
				}
			}

			if (Input == 'u' && c1.Get_Is_Locked() == true)
			{
				if (check_If_Busy(c1, Container) == true)
				{
					lvl_Up(c1, Container, p1);
					c1.Unselect();
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