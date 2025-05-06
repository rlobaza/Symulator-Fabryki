#pragma once

#include <string>

#include "Building.h"
#include "Own_List.h"

class Road : public Building
{

protected:

	static int Cost;
	static char Icon;

	bool Is_Visited;
	Own_List<Road*> Connected;

public:

	Road(int, int);
	~Road();

	void Set_Is_Visited(bool);

	bool Get_Is_Visited();
	Own_List<Road*>& Get_Connected();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();
	virtual std::string Stats_String(int);

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
	virtual int Get_Cost();
};