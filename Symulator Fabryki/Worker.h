#pragma once

#include <queue>




#include "Screen_Object.h"
#include "Building.h"
#include "Road.h"
#include "Road_Container.h"
#include "find_Target.h"
#include "Task.h"


class Task;

class Worker : public Screen_Object
{

private:

	int Cost;
	char Icon;

	bool Is_Working;
	bool Is_On_Road;

	Task* Current_Task;

	std::queue<Road*> Route;
	Road_Container& Roads;
	Building_Container& Buildings;

public:

	Worker(int, int, Road_Container&, Building_Container&);
	~Worker();


	void Set_Cost(int);
	void Set_Icon(char);
	void Set_Is_Working(bool);
	void Set_Is_On_Road(bool);
	void Set_Current_Task(Task*);
	void Set_Route(std::queue<Road*>);

	int Get_Cost();
	char Get_Icon();
	bool& Get_Is_Working();
	bool& Get_Is_On_Road();
	Task* Get_Current_Task();
	std::queue<Road*>& Get_Route();

	virtual void Simulate();
	void Go();



};

