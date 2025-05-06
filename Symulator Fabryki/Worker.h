#pragma once

#include <queue>




#include "Screen_Object.h"
#include "Building.h"





class Worker : public Screen_Object
{

private:

	int Cost;
	char Icon;

	bool Is_Working;
	bool Is_On_Road;
	std::queue<char> Route;
	Building* Target;

public:

	Worker(int, int);
	~Worker();


	void Set_Cost(int);
	void Set_Icon(char);
	void Set_Is_Working(bool);
	void Set_Is_On_Road(bool);
	void Set_Route(std::queue<char>);
	void Set_Target(Building*);

	int Get_Cost();
	char Get_Icon();
	bool& Get_Is_Working();
	bool& Get_Is_On_Road();
	std::queue<char>& Get_Route();
	Building* Get_Target();

	Building* Find_Target();

	virtual void Simulate();



};

