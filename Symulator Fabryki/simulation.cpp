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

#include "Worker.h"

#include "simulation.h"

void simulation(Screen& s1, Cursor& c1, char& Input, bool& Gameover, Player& p1, Screen_Object_Container& Container, Clock& clk)
{
	while (Gameover == false)
	{




		for (int i = 0; i < Container.Get_Control_Laboratories().size(); i++)
		{
			
		}

		for (int i = 0; i < Container.Get_Packaging_Areas().size(); i++)
		{
			
		}

		for (int i = 0; i < Container.Get_Production_Halls().size(); i++)
		{
			
		}

		for (int i = 0; i < Container.Get_Roads().size(); i++)
		{
			
		}

		for (int i = 0; i < Container.Get_Sorting_Areas().size(); i++)
		{
			
		}

		for (int i = 0; i < Container.Get_Staff_Welfare_Areas().size(); i++)
		{
			
		}

		for (int i = 0; i < Container.Get_Warehouses().size(); i++)
		{
			
		}






		for (int i = 0; i < Container.Get_Loading_Ramps().size(); i++) //Rampy 2s
		{
			Container.Get_Loading_Ramps()[i].Simulate();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		//clk.Set_End_Time();
	}
}