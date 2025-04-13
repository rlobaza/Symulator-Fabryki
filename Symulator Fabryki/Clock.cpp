
#include <chrono>
#include <vector>
#include <thread>
#include <iostream>

#include "framerate.h"
#include "Clock.h"


Clock::Clock(double target)
{
	FPS = 0;
	TargetFPS = target;
	duration = 0;
	duration2 = 0;
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
		duration2 = SleepForMS;
	}
	else
	{
		std::this_thread::sleep_for(std::chrono::milliseconds((duration / SleepForMS) * SleepForMS - duration % SleepForMS));
		//std::this_thread::sleep_for(std::chrono::milliseconds(duration%SleepForMS));
		duration2 = duration + duration%SleepForMS;
	}

	duration = 0;
	Durations.clear();
}

std::string Clock::Print_FPS()
{
	std::string str;
	str = str + "Frame Duration: " + std::to_string(duration2) + " ms" + '\n';
	str = str + "FPS: " + std::to_string(FPS) + '\n';
	str = str + "Pominiete klatki: " + std::to_string(duration2/SleepForMS - 1) + '\n';
	str = str + '\n';

	return str;
}

void Clock::Set_FPS()
{
	if (duration <= SleepForMS)
	{
		FPS = TargetFPS;
	}
	else
	{
		FPS = 1000 / (duration);
	}
}