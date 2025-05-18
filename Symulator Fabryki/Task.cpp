

#include<string>

#include "Task.h"
#include "Building.h"
#include "Building_Container.h"
#include "Worker.h"
#include "Worker_Container.h"



Task::Task(std::string what, Building* from, Building* to, Worker* who) : What(what), From(from), To(to), Who(who)
{

}

Task::~Task()
{

}

void Task::Set_What(std::string param)
{
	What = param;
}

void Task::Set_From(Building* param)
{
	From = param;
}

void Task::Set_To(Building* param)
{
	To = param;
}

void Task::Set_Who(Worker* param)
{
	Who = param;
}

std::string Task::Get_What()
{
	return What;
}

Building* Task::Get_From()
{
	return From;
}

Building* Task::Get_To()
{
	return To;
}

Worker* Task::Get_Who()
{
	return Who;
}