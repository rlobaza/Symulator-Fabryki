
#include <queue>
#include <iostream>


#include "Worker.h"
#include "Screen_Object.h"
#include "Building.h"
#include "find_Route.h"
#include "Road_Container.h"
#include "find_Target.h"

Worker::Worker(int x, int y, Road_Container& roads, Building_Container& buildings) : Is_Working(false), Target(nullptr), Is_On_Road(false), Cost(1), Icon('~'), Roads(roads), Buildings(buildings)
{
	this->Set_PosX(x);
	this->Set_PosY(y);
}

Worker::~Worker()
{

}

void Worker::Set_Cost(int param)
{
	Cost = param;
}

void Worker::Set_Icon(char param)
{
	Icon = param;
}

void Worker::Set_Is_Working(bool param)
{
	Is_Working = param;
}

void Worker::Set_Is_On_Road(bool param)
{
	Is_On_Road = param;
}

void Worker::Set_Route(std::queue<Road*> param)
{
	Route = param;
}

void Worker::Set_Target(Building* ptr)
{
	Target = ptr;
}

int Worker::Get_Cost()
{
	return Cost;
}

char Worker::Get_Icon()
{
	return Icon;
}

bool& Worker::Get_Is_Working()
{
	return Is_Working;
}

bool& Worker::Get_Is_On_Road()
{
	return Is_On_Road;
}

std::queue<Road*>& Worker::Get_Route()
{
	return Route;
}

Building* Worker::Get_Target()
{
	return Target;
}

void Worker::Simulate()
{

	if (Is_Working == false)
	{
		Target = find_Target(Buildings);

		if (Target != nullptr && Is_Working == false)
		{
			find_Route(this, Target, Roads, Route);
			Set_Is_Working(true);
		}

	}

	if (Route.empty() == false)
	{
		Go();
	}

	if (Route.empty() == true)
	{
		Set_Is_Working(false);
	}


}

void Worker::Go()
{
	Set_PosX(Route.front()->Get_PosX());
	Set_PosY(Route.front()->Get_PosY());
	Route.pop();
}