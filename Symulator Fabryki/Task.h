#pragma once


#include<string>

#include "Building.h"
#include "Building_Container.h"
#include "Worker.h"
#include "Worker_Container.h"


class Worker;

class Task
{

private:

	std::string What;
	Building* From;
	Building* To;
	Worker* Who;

public:

	Task(std::string, Building*, Building*, Worker*);
	~Task();

	void Set_What(std::string);
	void Set_From(Building*);
	void Set_To(Building*);
	void Set_Who(Worker*);

	std::string Get_What();
	Building* Get_From();
	Building* Get_To();
	Worker* Get_Who();

};

