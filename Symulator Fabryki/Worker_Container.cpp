
#include <mutex>

#include "Worker.h"
#include "Worker_Container.h"


Worker_Container::Worker_Container()
{

}

Worker_Container::~Worker_Container()
{

}

void Worker_Container::Add_Workers(Worker* ptr)
{
	Workers.Push_Back(ptr);
}

void Worker_Container::Remove_Workers()
{

}

Own_List<Worker*>& Worker_Container::Get_Workers()
{
	return Workers;
}

std::recursive_mutex& Worker_Container::Get_Mutex()
{
	return mtx;
}