
#include <queue>
#include <iostream>


#include "Worker.h"
#include "Screen_Object.h"
#include "Building.h"
#include "find_Route.h"
#include "Road_Container.h"
#include "Task_Container.h"
#include "find_Target.h"

Worker::Worker(int x, int y, Road_Container& roads, Building_Container& buildings, Task_Container& tasks) : Was_Route_Found(false),  After_First_Target(false), Current_Task(nullptr), Cost(1), Icon('?'), Roads(roads), Buildings(buildings), Tasks(tasks)
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

void Worker::Set_Was_Route_Found(bool param)
{
	Was_Route_Found = param;
}

void Worker::Set_After_First_Target(bool param)
{
	After_First_Target = param;
}

void Worker::Set_Current_Task(Task* param)
{
	Current_Task = param;
}

void Worker::Set_Route(std::queue<Road*> param)
{
	Route = param;
}

int Worker::Get_Cost()
{
	return Cost;
}

char Worker::Get_Icon()
{
	return Icon;
}

Task* Worker::Get_Current_Task()
{
	return Current_Task;
}

std::queue<Road*>& Worker::Get_Route()
{
	return Route;
}

void Worker::Simulate()
{
	if (Current_Task != nullptr)
	{
		Icon = 'O';

		if (After_First_Target == false)
		{
			if (Route.size() == 0 && Was_Route_Found == false)
			{
				find_Route(this, Current_Task->Get_From(), Roads, Route);
				Was_Route_Found = true;
			}

			if (Route.size() != 0)
			{
				Go();
			}

			if (Route.size() == 0 && Was_Route_Found == true)
			{
				if (Current_Task->Get_What() == "Materials")
				{
					Current_Task->Get_From()->Set_Materials_Storage_Used(Current_Task->Get_From()->Get_Materials_Storage_Used() - 1);
					Current_Task->Get_From()->Set_Materials_Reserved(Current_Task->Get_From()->Get_Materials_Reserved() - 1);
				}
				if (Current_Task->Get_What() == "Sorted_Materials")
				{
					Current_Task->Get_From()->Set_Sorted_Materials_Storage_Used(Current_Task->Get_From()->Get_Sorted_Materials_Storage_Used() - 1);
					Current_Task->Get_From()->Set_Sorted_Materials_Reserved(Current_Task->Get_From()->Get_Sorted_Materials_Reserved() - 1);
				}
				if (Current_Task->Get_What() == "Ready_Products")
				{
					Current_Task->Get_From()->Set_Ready_Products_Storage_Used(Current_Task->Get_From()->Get_Ready_Products_Storage_Used() - 1);
					Current_Task->Get_From()->Set_Ready_Products_Reserved(Current_Task->Get_From()->Get_Ready_Products_Reserved() - 1);
				}
				if (Current_Task->Get_What() == "Packed_Products")
				{
					Current_Task->Get_From()->Set_Packed_Products_Storage_Used(Current_Task->Get_From()->Get_Packed_Products_Storage_Used() - 1);
					Current_Task->Get_From()->Set_Packed_Products_Reserved(Current_Task->Get_From()->Get_Packed_Products_Reserved() - 1);
				}

				After_First_Target = true;
				Was_Route_Found = false;
			}
		}
		else
		{
			Icon = '@';

			if (Route.size() == 0 && Was_Route_Found == false)
			{
				find_Route(this, Current_Task->Get_To(), Roads, Route);
				Was_Route_Found = true;
			}

			if (Route.size() != 0)
			{
				Go();
			}

			if (Route.size() == 0 && Was_Route_Found == true)
			{
				std::lock_guard<std::recursive_mutex> lock(Tasks.Get_Mutex());

				if (Current_Task->Get_What() == "Materials")
				{
					Current_Task->Get_To()->Set_Materials_Storage_Used(Current_Task->Get_To()->Get_Materials_Storage_Used() + 1);
					Current_Task->Get_To()->Set_Materials_Storage_Reserved(Current_Task->Get_To()->Get_Materials_Storage_Reserved() - 1);
				}
				if (Current_Task->Get_What() == "Sorted_Materials")
				{
					Current_Task->Get_To()->Set_Sorted_Materials_Storage_Used(Current_Task->Get_To()->Get_Sorted_Materials_Storage_Used() + 1);
					Current_Task->Get_To()->Set_Sorted_Materials_Storage_Reserved(Current_Task->Get_To()->Get_Sorted_Materials_Storage_Reserved() - 1);
				}
				if (Current_Task->Get_What() == "Ready_Products")
				{
					Current_Task->Get_To()->Set_Ready_Products_Storage_Used(Current_Task->Get_To()->Get_Ready_Products_Storage_Used() + 1);
					Current_Task->Get_To()->Set_Ready_Products_Storage_Reserved(Current_Task->Get_To()->Get_Ready_Products_Storage_Reserved() - 1);
				}
				if (Current_Task->Get_What() == "Packed_Products")
				{
					Current_Task->Get_To()->Set_Packed_Products_Storage_Used(Current_Task->Get_To()->Get_Packed_Products_Storage_Used() + 1);
					Current_Task->Get_To()->Set_Packed_Products_Storage_Reserved(Current_Task->Get_To()->Get_Packed_Products_Storage_Reserved() - 1);
				}

				After_First_Target = false;
				Was_Route_Found = false;

				for (int i = 0; i < Tasks.Get_Tasks().Get_Size(); i++)
				{
					if (Tasks.Get_Tasks()[i] == Current_Task)
					{
						Tasks.Remove_Tasks(i);
						i--;
					}
				}

				delete Current_Task;
				Current_Task = nullptr;
			}
		}

	}
	else
	{
		Icon = '?';
	}
}

void Worker::Go()
{
	Set_PosX(Route.front()->Get_PosX());
	Set_PosY(Route.front()->Get_PosY());
	Route.pop();
}