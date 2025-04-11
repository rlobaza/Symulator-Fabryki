//basic
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <semaphore>

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
#include "Semaphore_1.h"
#include "Semaphore_2.h"
#include "Semaphore_3.h"
#include "Semaphore_4.h"
#include "Clock.h"

//screen objects
#include "Screen_Object.h"
#include "Screen_Object_Container.h"
#include "Control_Laboratory.h"
#include "Loading_Ramp.h"
#include "Packaging_Area.h"
#include "Production_Hall.h"
#include "Road.h"
#include "Sorting_Area.h"
#include "Staff_Welfare_Area.h"
#include "Warehouse.h"
#include "Worker.h"

//functions
#include "load_To_Screen.h"
#include "framerate.h"
#include "print_Time.h"
#include "print_Player_Stats.h"
#include "initial_Buffer.h"
#include "next_Frame.h"


int main()
{



	bool Gameover = false;
	char Input = ' ';

	Screen s1;
	Cursor c1;
	Player p1;
	Clock clk(/*framerate()*/60);
	Screen_Object_Container Container;
	Frame frm;


	p1.ChangeMoney(10000);

	std::thread Input_Thread(user_Input, std::ref(Input), std::ref(Gameover), std::ref(clk));

	std::thread Input_Keys_Thread(user_Input_Keys, std::ref(s1), std::ref(c1), std::ref(Input), std::ref(Gameover), std::ref(p1), std::ref(Container), std::ref(clk));

	std::thread Simulation_Thread(simulation, std::ref(s1), std::ref(c1), std::ref(Input), std::ref(Gameover), std::ref(p1), std::ref(Container), std::ref(clk));



	initial_Buffer();


	while (Gameover == false)
	{
		clk.Set_Start_Time();



		//////////////////////////////////////////////

		s1.Clear();

		load_To_Screen(s1, Container);

		s1.Input(c1.PosX, c1.PosY, c1.Icon);


		/////////////////////////////////////////////

		frm.Clear_Frame();



		frm.Add_To_Frame(next_Frame());

		frm.Add_To_Frame(print_Time());

		frm.Add_To_Frame(s1.Output());

		frm.Add_To_Frame(print_Player_Stats(p1));

		frm.Add_To_Frame(print_All_Objects(Container));

		frm.Add_To_Frame(clk.Print_FPS());



		frm.Print_Frame();

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