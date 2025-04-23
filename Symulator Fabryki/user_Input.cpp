#include <conio.h>
#include <iostream>
#include <chrono>
#include <thread>

#include "user_Input.h"
#include "Screen.h"


void user_Input(char& Input, bool& Gameover)
{

	while (true)
	{

		if (_kbhit)
		{
			Input = _getch();
		}
		if (Gameover == true)
		{
			return;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(8));
	}
}