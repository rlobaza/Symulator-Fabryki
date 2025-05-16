#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>

#include "User_Input_Keys.h"
#include "Screen.h"
#include "Cursor.h"
#include "Screen_Object.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"
#include "Production_Hall.h"
#include "Road.h"
#include "Warehouse.h"
#include "Player.h"
#include "check_If_Busy.h"
#include "sell_Building.h"
#include "Building.h"

#include "simulation.h"

void simulation(Screen& s1, Cursor& c1, char& Input, bool& Gameover, Player& p1, Building_Container& Buildings, Worker_Container& Workers)
{

	while (Gameover == false)
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
		{
			std::lock_guard<std::recursive_mutex> lock1(Buildings.Get_Mutex());
			Buildings.Get_Buildings()[i]->Simulate();
			Buildings.Get_Buildings()[i]->Check_If_Ready();
		}

		for (int i = 0; i < Workers.Get_Workers().Get_Size(); i++)
		{
			std::lock_guard<std::recursive_mutex> lock2(Workers.Get_Mutex());
			Workers.Get_Workers()[i]->Simulate();
		}

	}
}