#include <conio.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "Semaphore_1.h"
#include "Semaphore_2.h"
#include "Semaphore_3.h"
#include "Semaphore_4.h"
#include "Clock.h"

#include "user_Input.h"
#include "Screen.h"

void user_Input(char& Input, bool& Gameover, Clock& clk)
{
	while (true)
	{
		clk.Set_Start_Time();
		if (_kbhit)
		{
			Input = _getch();
		}
		if (Gameover == true)
		{
			return;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(8));


		//clk.Set_End_Time();
	}
}