#pragma once

#include <queue>




#include "Screen_Object.h"
#include "Building.h"
#include "Road.h"
#include "Road_Container.h"
#include "Task_Container.h"
#include "find_Target.h"
#include "Task.h"


class Task;

class Task_Container;

class Worker : public Screen_Object
{

private:

	int Cost;
	char Icon;

	bool Was_Route_Found;
	bool After_First_Target;

	Task* Current_Task;

	std::queue<Road*> Route;
	Road_Container& Roads;
	Building_Container& Buildings;
	Task_Container& Tasks;

public:

	Worker(int, int, Road_Container&, Building_Container&, Task_Container&);
	~Worker();


	void Set_Cost(int);
	void Set_Icon(char);
	
	void Set_Was_Route_Found(bool);
	void Set_After_First_Target(bool);

	void Set_Current_Task(Task*);
	void Set_Route(std::queue<Road*>);

	int Get_Cost();
	char Get_Icon();

	bool Get_Was_Route_Found();
	bool Get_After_First_Target();

	Task* Get_Current_Task();
	std::queue<Road*>& Get_Route();

	virtual void Simulate();
	void Go();



};

