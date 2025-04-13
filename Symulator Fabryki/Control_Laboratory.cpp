

#include "Control_Laboratory.h"
#include "Screen_Object.h"

int Control_Laboratory::Cost = 500;

Control_Laboratory::Control_Laboratory(int PosX, int PosY) : Screen_Object(PosX, PosY, 'W')
{

}

Control_Laboratory::~Control_Laboratory()
{

}

void Control_Laboratory::Move(int x, int y)
{
	PosX = x;
	PosY = y;
}

void Control_Laboratory::Simulate()
{

}

int Control_Laboratory::Get_Cost()
{
	return Cost;
}

void Control_Laboratory::Lvl_Up()
{

}