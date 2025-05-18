#pragma once

#include <mutex>

#include "Task.h"
#include "Own_List.h"

class Task;

class Task_Container
{

private:

	Own_List<Task*> Tasks;

	std::recursive_mutex mtx;

public:

	Task_Container();
	~Task_Container();

	void Add_Tasks(Task*);
	void Remove_Tasks(int);
	Own_List<Task*>& Get_Tasks();
	std::recursive_mutex& Get_Mutex();

};
