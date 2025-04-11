#pragma once

#include <chrono>
#include <vector>

#include "framerate.h"

class Clock
{

private:

	double FPS;
	double TargetFPS;
	long long duration;
	long long duration2;
	int SleepForMS;

	std::chrono::steady_clock::time_point start_time;
	std::chrono::steady_clock::time_point end_time;

	std::vector<long long> Durations;

public:

	Clock(double);
	~Clock();

	void Set_Start_Time();
	void Set_End_Time();
	void Add_Durations();
	void Sleep();
	std::string Print_FPS();
	void Set_FPS();

};