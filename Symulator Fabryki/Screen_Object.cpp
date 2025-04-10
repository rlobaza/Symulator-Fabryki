#include <iostream>

#include "Screen_Object.h"
#include "create_ID.h"

int Screen_Object::NumberOfObjects = 0;

Screen_Object::Screen_Object()
{
	ID = create_ID();
	NumberOfObjects++;
	SelfPointer = this;

	PosX = -1;
	PosY = -1;
	Icon = '$';
}

Screen_Object::Screen_Object(int PosX, int PosY, char Icon) : PosX(PosX), PosY(PosY), Icon(Icon)
{
	ID = create_ID();
	NumberOfObjects++;
	SelfPointer = this;

}

Screen_Object::~Screen_Object()
{
	NumberOfObjects--;
}

void Screen_Object::Move()
{

}

void Screen_Object::Simulate()
{

}