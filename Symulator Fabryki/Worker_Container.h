#pragma once

#include <mutex>

#include "Worker.h"
#include "Own_List.h"


class Worker_Container
{

private:

	Own_List<Worker*> Workers;

	std::recursive_mutex mtx;

public:

	Worker_Container();
	~Worker_Container();

	void Add_Workers(Worker*);
	void Remove_Workers();
	Own_List<Worker*>& Get_Workers();
	std::recursive_mutex& Get_Mutex();

};

