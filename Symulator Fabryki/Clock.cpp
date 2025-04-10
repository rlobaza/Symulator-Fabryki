
#include <chrono>
#include <vector>
#include <thread>
#include <iostream>

#include "framerate.h"
#include "Clock.h"


Clock::Clock()
{
	FPS = 0;
	TargetFPS = framerate();
	duration = 0;
	SleepForMS = (1000 / TargetFPS);
}

Clock::~Clock()
{

}

void Clock::Set_Start_Time()
{
	start_time = std::chrono::high_resolution_clock::now();
}

void Clock::Set_End_Time()
{
	end_time = std::chrono::high_resolution_clock::now();
}

void Clock::Add_Durations()
{
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
	Durations.push_back(duration);
}

void Clock::Sleep()
{
	for (int i = 0; i < Durations.size(); i++)
	{
		duration += Durations[i];
	}


	if (duration < SleepForMS)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(SleepForMS - duration));
	}
	else
	{
		std::this_thread::sleep_for(std::chrono::milliseconds((duration / SleepForMS) * SleepForMS - duration % SleepForMS));
	}

	duration2 = duration;
	duration = 0;
	Durations.clear();
}

void Clock::Print_FPS()
{
	std::cout << std::endl;
	std::cout << "Frame Duration: " << duration2 << " ms" << std::endl;
	std::cout << "FPS: " << FPS << std::endl;
}

void Clock::Set_FPS()
{
	if (duration < SleepForMS)
	{
		FPS = TargetFPS;
	}
	else
	{
		FPS = 1000 / (duration);
	}
}