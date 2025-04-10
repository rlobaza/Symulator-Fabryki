#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>

#include "User_Input_Keys.h"
#include "Screen.h"
#include "Cursor.h"
#include "Screen_Object.h"
#include "Screen_Object_Container.h"
#include "Production_Hall.h"
#include "Road.h"
#include "Warehouse.h"
#include "Player.h"
#include "check_If_Busy.h"
#include "sell_Building.h"

#include "Semaphore_1.h"
#include "Semaphore_2.h"
#include "Semaphore_3.h"
#include "Semaphore_4.h"
#include "Clock.h"



void user_Input_Keys(Screen& s1, Cursor& c1, char& Input, bool& Gameover, Player& p1, Screen_Object_Container& Container, Clock& clk)
{
	while (true)
	{
		if (Gameover == true)
		{
			break;
		}




		if (Input == 'q')
		{
			Gameover = true;
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
			if (c1.Is_Locked == false)
			{
				c1.Select();
			}
			else
			{
				c1.Unselect();
			}
			
		}

		if (Input == '1' && c1.Is_Locked == true)
		{

		}

		if (Input == '2' && c1.Is_Locked == true)
		{
			if (check_If_Busy(c1, Container) == false)
			{
				if (p1.Money >= Loading_Ramp::Get_Cost())
				{
					p1.ChangeMoney(-Loading_Ramp::Get_Cost());
					Container.Add_Loading_Ramps(Loading_Ramp(c1.SelX, c1.SelY));
					c1.Unselect();
				}
			}
		}

		if (Input == '3' && c1.Is_Locked == true)
		{

		}

		if (Input == '4' && c1.Is_Locked == true) //Production Hall
		{
			if (check_If_Busy(c1, Container) == false)
			{
				if (p1.Money >= Production_Hall::Cost)
				{
					p1.ChangeMoney(-Production_Hall::Cost);
					Container.Add_Production_Halls(Production_Hall(c1.SelX, c1.SelY));
					c1.Unselect();
				}
			}
		}

		if (Input == '5' && c1.Is_Locked == true) //Road
		{
			if (check_If_Busy(c1, Container) == false)
			{
				if (p1.Money >= Road::Cost)
				{
					p1.ChangeMoney(-Road::Cost);
					Container.Add_Roads(Road(c1.SelX, c1.SelY));
					c1.Unselect();
				}
			}
		}

		if (Input == '6' && c1.Is_Locked == true)
		{

		}

		if (Input == '7' && c1.Is_Locked == true)
		{

		}

		if (Input == '8' && c1.Is_Locked == true) //Warehouse
		{
			if (check_If_Busy(c1, Container) == false)
			{
				if (p1.Money >= Warehouse::Get_Cost())
				{
					p1.ChangeMoney(-Warehouse::Get_Cost());
					Container.Add_Warehouses(Warehouse(c1.SelX, c1.SelY));
					p1.Update_Maxes(Container);
					c1.Unselect();
				}
			}
		}

		if (Input == 'x' && c1.Is_Locked == true)
		{
			if (check_If_Busy(c1, Container) == true)
			{
				sell_Building(c1, Container, p1);
				p1.Update_Maxes(Container);
				c1.Unselect();
			}
		}

		if (Input == 't' && c1.Is_Locked == true) //Worker
		{
			if (check_If_Busy(c1, Container) == false)
			{
				Container.Add_Workers(Worker(c1.SelX, c1.SelY));
				c1.Unselect();
			}
		}



		Input = ' ';



		std::this_thread::sleep_for(std::chrono::milliseconds(16));

		//clk.Set_End_Time();
	}
}