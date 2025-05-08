#pragma once

#include <queue>




#include "Screen_Object.h"
#include "Building.h"
#include "Road.h"
#include "Road_Container.h"
#include "find_Target.h"





class Worker : public Screen_Object
{

private:

	int Cost;
	char Icon;

	bool Is_Working;
	bool Is_On_Road;
	std::queue<Road*> Route;
	Building* Target;
	Road_Container& Roads;
	Building_Container& Buildings;

public:

	Worker(int, int, Road_Container&, Building_Container&);
	~Worker();


	void Set_Cost(int);
	void Set_Icon(char);
	void Set_Is_Working(bool);
	void Set_Is_On_Road(bool);
	void Set_Route(std::queue<Road*>);
	void Set_Target(Building*);

	int Get_Cost();
	char Get_Icon();
	bool& Get_Is_Working();
	bool& Get_Is_On_Road();
	std::queue<Road*>& Get_Route();
	Building* Get_Target();

	virtual void Simulate();
	void Go();



};

