#pragma once

#include <string>

#include "Building.h"
#include "Own_List.h"

class Road : public Building
{

protected:

	char Icon;
	static std::string Name;

	bool Is_Visited;
	Own_List<Road*> Connected;
	int Distance;
	Road* Previous;
	bool Is_Added;

public:

	static int Cost;

	Road(int, int);
	~Road();

	void Set_Is_Visited(bool);
	void Set_Distance(int);
	void Set_Previous(Road*);
	void Set_Is_Added(bool);
	void Set_Icon(char);

	bool Get_Is_Visited();
	Own_List<Road*>& Get_Connected();
	int Get_Distance();
	Road* Get_Previous();
	bool Get_Is_Added();

	//Building:
	virtual void Lvl_Up();
	virtual void Calculate_Storage();
	virtual std::string Stats_String(int);
	virtual std::string Get_Name();

	//Screen_Object:
	virtual char Get_Icon();
	virtual void Simulate();
	virtual int Get_Cost();
	virtual void Check_If_Ready();
};