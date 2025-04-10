#pragma once

#include "Screen_Object.h"
#include <queue>

class Worker : public Screen_Object
{

private:

	char Slot;


public:

	Worker(int, int);
	~Worker();

	void Set_Slot(char);

	char Get_Slot();

	virtual void Move(char); //L left R right U up D down
	virtual void Simulate();
	void Take();
	void Leave();


};