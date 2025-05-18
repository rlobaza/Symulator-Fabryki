#include <mutex>

#include "Task.h"
#include "Task_Container.h"





Task_Container::Task_Container()
{

}

Task_Container::~Task_Container()
{

}

void Task_Container::Add_Tasks(Task* ptr)
{
	std::lock_guard<std::recursive_mutex> lock(mtx);
	Tasks.Push_Back(ptr);
}

void Task_Container::Remove_Tasks(int param)
{
	Tasks.Erase(param);
}

Own_List<Task*>& Task_Container::Get_Tasks()
{
	return Tasks;
}

std::recursive_mutex& Task_Container::Get_Mutex()
{
	return mtx;
}