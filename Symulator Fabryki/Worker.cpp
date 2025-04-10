

#include "Worker.h"
#include "Screen_Object.h"
#include "Screen_Object_Container.h"
#include <queue>


Worker::Worker(int PosX, int PosY) : Screen_Object(PosX, PosY, '~')
{
	Slot = '~';
}

Worker::~Worker()
{

}

void Worker::Set_Slot(char c)
{
	Slot = c;
}

char Worker::Get_Slot()
{
	return Slot;
}

void Worker::Move(char c) //L left R right U up D down
{
	if (c == 'L')
	{
		PosX = PosX - 1;
		return;
	}

	if (c == 'R')
	{
		PosX = PosX + 1;
		return;
	}

	if (c == 'U')
	{
		PosY = PosY - 1;
		return;
	}

	if (c == 'D')
	{
		PosY = PosY + 1;
		return;
	}
}

void Worker::Simulate()
{

}

void Worker::Take()
{

}

void Worker::Leave()
{

}