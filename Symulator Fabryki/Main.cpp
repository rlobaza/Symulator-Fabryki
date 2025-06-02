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
#include "print_Selected.h"
#include "ask_Nickname.h"
#include "setConsoleSize.h"
#include "save_Leaderboard.h"

//UI
#include "Menu.h"
#include "Button.h"
#include "New_Game.h"
#include "Load_Game.h"
#include "Quit.h"

//tasks
#include "Task.h"
#include "Task_Container.h"
#include "update_Tasks.h"

//sound

//Score
#include "Score.h"
#include "print_Leaderboard.h"
#include "add_Score.h"
#include "load_Leaderboard.h"
#include "sort_Leaderboard.h"

int main()
{
	SetConsoleOutputCP(1250);
	setConsoleSize(110, 50);

	bool Gameover = false;
	bool In_Menu = true;
	bool In_Leaderboard = false;
	char Input = ' ';

	Building_Container Buildings;
	Road_Container Roads;
	Worker_Container Workers;
	Task_Container Tasks;

	Own_List<Score*> Leaderboard;
	load_Leaderboard(Leaderboard);
	sort_Leaderboard(Leaderboard);

	Screen s1;
	Cursor c1;
	Player p1(Buildings, ask_Nickname());
	Clock clk(framerate());

	Frame frm;

	Menu menu_1;

	p1.Change_Money(10000);

	std::thread Input_Thread(user_Input, std::ref(Input), std::ref(Gameover));

	std::thread Input_Keys_Thread(user_Input_Keys, std::ref(s1), std::ref(c1), std::ref(Input), std::ref(Gameover), std::ref(p1), std::ref(Buildings), std::ref(Workers), std::ref(Roads), std::ref(Tasks), std::ref(In_Menu), std::ref(menu_1), std::ref(In_Leaderboard), std::ref(Leaderboard));

	std::thread Simulation_Thread(simulation, std::ref(s1), std::ref(c1), std::ref(Input), std::ref(Gameover), std::ref(p1), std::ref(Buildings), std::ref(Workers), std::ref(Tasks), std::ref(Roads));

	

	initial_Buffer(10000);


	while (Gameover == false)
	{

		clk.Set_Start_Time();

		if (In_Menu == true && In_Leaderboard == false)
		{

			frm.Clear_Frame();



			frm.Add_To_Frame(next_Frame());

			frm.Add_To_Frame(menu_1.Print_Menu());

			frm.Add_To_Frame(generate_Empty_Lines(18));

			frm.Add_To_Frame("e -> Wybierz");
			frm.Add_To_Frame("w, s -> Kursor");


			frm.Print_Frame();

		}

		if (In_Menu == true && In_Leaderboard == true)
		{

			frm.Clear_Frame();



			frm.Add_To_Frame(next_Frame());

			frm.Add_To_Frame(print_Leaderboard(Leaderboard));

			frm.Add_To_Frame(generate_Empty_Lines(18));

			frm.Add_To_Frame("q -> Menu G³ówne");



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

			frm.Add_To_Frame(clk.Print_FPS());

			frm.Add_To_Frame(print_Time());

			frm.Add_To_Frame(s1.Output());

			frm.Add_To_Frame(print_Player_Stats(p1, Workers));

			//frm.Add_To_Frame(print_All_Objects(Buildings));

			frm.Add_To_Frame(print_Selected(Buildings, c1));



			frm.Print_Frame();

		}



		///////////////////////////////////////////////

		clk.Set_End_Time();
		clk.Add_Durations();
		clk.Set_FPS();
		clk.Sleep();

	}

	system("cls");

	save_Leaderboard(Leaderboard);

	Input_Thread.join();
	Input_Keys_Thread.join();
	Simulation_Thread.join();

	return 0;
}