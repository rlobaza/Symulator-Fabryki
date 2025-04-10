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


int main()
{



	bool Gameover = false;
	char Input = ' ';

	double FPS = 0;
	double TargetFPS = framerate();
	long long duration = 0;
	int SleepForMS = (1000 / TargetFPS);

	Screen s1;
	Cursor c1;
	Player p1;
	Clock clk;

	Screen_Object_Container Container;


	p1.ChangeMoney(10000);

	std::thread Input_Thread(user_Input, std::ref(Input), std::ref(Gameover), std::ref(clk));

	std::thread Input_Keys_Thread(user_Input_Keys, std::ref(s1), std::ref(c1), std::ref(Input), std::ref(Gameover), std::ref(p1), std::ref(Container), std::ref(clk));

	std::thread Simulation_Thread(simulation, std::ref(s1), std::ref(c1), std::ref(Input), std::ref(Gameover), std::ref(p1), std::ref(Container), std::ref(clk));


	for (int i = 0; i < 10000; i++)
	{
		std::cout << std::endl;
	}

	while (Gameover == false)
	{
		clk.Set_Start_Time();



		//////////////////////////////////////////////

		s1.Clear();

		load_To_Screen(s1, Container);

		s1.Input(c1.PosX, c1.PosY, c1.Icon);


		/////////////////////////////////////////////

		print_Time();

		s1.Output();

		print_Player_Stats(p1);

		std::cout << std::endl;

		print_All_Objects(Container);

		clk.Print_FPS();

		///////////////////////////////////////////////




		

		clk.Set_End_Time();
		clk.Add_Durations();
		clk.Set_FPS();
		clk.Sleep();

		for (int i = 0; i < 50; i++)
		{
			std::cout << std::endl;
		}
	}

	Input_Thread.join();
	Input_Keys_Thread.join();
	Simulation_Thread.join();

	return 0;
}