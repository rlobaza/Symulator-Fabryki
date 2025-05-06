
#include <queue>



#include "Worker.h"
#include "Screen_Object.h"
#include "Building.h"

Worker::Worker(int x, int y) : Is_Working(false), Target(nullptr), Is_On_Road(false), Cost(1), Icon('~')
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

void Worker::Set_Route(std::queue<char> param)
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

std::queue<char>& Worker::Get_Route()
{
	return Route;
}

Building* Worker::Get_Target()
{
	return Target;
}

Building* Worker::Find_Target()
{
	return nullptr;
}

void Worker::Simulate()
{

	if (Is_Working == false)
	{
		Find_Target();

		if (Target != nullptr)
		{
		}
		
		Set_Is_Working(true);
	}


}