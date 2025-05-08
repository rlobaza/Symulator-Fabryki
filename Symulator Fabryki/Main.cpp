//basic
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <semaphore>
#include "windows.h"
#include <fstream>

//threads
#include "user_Input.h"
#include "User_Input_Keys.h"
#include "simulation.h"

//classes
#include "Screen.h"
#include "Cursor.h"
#include "Player.h"
#include "print_All_Objects.h"
#include "Frame.h"

//sync
#include "Clock.h"

//screen objects
#include "Screen_Object.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"
#include "Control_Laboratory.h"
#include "Loading_Ramp.h"
#include "Packaging_Area.h"
#include "Production_Hall.h"
#include "Road.h"
#include "Sorting_Area.h"
#include "Staff_Welfare_Area.h"
#include "Warehouse.h"

//functions
#include "load_To_Screen.h"
#include "framerate.h"
#include "print_Time.h"
#include "print_Player_Stats.h"
#include "initial_Buffer.h"
#include "next_Frame.h"
#include "generate_Empty_Lines.h"
#include "find_Target.h"

//UI
#include "Menu.h"
#include "Button.h"
#include "New_Game.h"
#include "Load_Game.h"
#include "Quit.h"


int main()
{

	SetConsoleOutputCP(1250);

	bool Gameover = false;
	bool In_Menu = true;
	char Input = ' ';

	Screen s1;
	Cursor c1;
	Player p1;
	Clock clk(framerate());

	Building_Container Buildings;
	Road_Container Roads;
	Worker_Container Workers;

	Frame frm;



	Menu menu_1;



	p1.Change_Money(10000);

	std::thread Input_Thread(user_Input, std::ref(Input), std::ref(Gameover));

	std::thread Input_Keys_Thread(user_Input_Keys, std::ref(s1), std::ref(c1), std::ref(Input), std::ref(Gameover), std::ref(p1), std::ref(Buildings), std::ref(Workers), std::ref(Roads), std::ref(In_Menu), std::ref(menu_1));

	std::thread Simulation_Thread(simulation, std::ref(s1), std::ref(c1), std::ref(Input), std::ref(Gameover), std::ref(p1), std::ref(Buildings), std::ref(Workers));

	

	initial_Buffer(10000);


	while (Gameover == false)
	{

		clk.Set_Start_Time();

		if (In_Menu == true)
		{

			frm.Clear_Frame();



			frm.Add_To_Frame(next_Frame());

			frm.Add_To_Frame(menu_1.Print_Menu());

			frm.Add_To_Frame(generate_Empty_Lines(15));



			frm.Print_Frame();

		}

		if (In_Menu == false)
		{

			//////////////////////////////////////////////

			s1.Clear();

			load_To_Screen(s1, Buildings, Workers);

			s1.Input(c1.Get_PosX(), c1.Get_PosY(), c1.Get_Icon());


			/////////////////////////////////////////////

			frm.Clear_Frame();



			frm.Add_To_Frame(next_Frame());

			frm.Add_To_Frame(print_Time());

			frm.Add_To_Frame(s1.Output());

			frm.Add_To_Frame(print_Player_Stats(p1));

			frm.Add_To_Frame(print_All_Objects(Buildings));

			frm.Add_To_Frame(clk.Print_FPS());

			if (Workers.Get_Workers().Get_Size() != 0)
			{
				frm.Add_To_Frame(std::to_string(Workers.Get_Workers()[0]->Get_Route().size()));
			}

			if(find_Target(Buildings) != nullptr)
			frm.Add_To_Frame("TRUE");



			frm.Print_Frame();

		}



		///////////////////////////////////////////////

		clk.Set_End_Time();
		clk.Add_Durations();
		clk.Set_FPS();
		clk.Sleep();

	}

	system("cls");

	Input_Thread.join();
	Input_Keys_Thread.join();
	Simulation_Thread.join();

	return 0;
}