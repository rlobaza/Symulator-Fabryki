#include <iostream>

#include "Screen_Object.h"
#include "create_ID.h"

Screen_Object::Screen_Object()
{
	ID = create_ID();
	PosX = -1;
	PosY = -1;
	Icon = '$';
}

Screen_Object::~Screen_Object()
{

}

int Screen_Object::Get_ID()
{
	return ID;
}

int Screen_Object::Get_PosX()
{
	return PosX;
}

int Screen_Object::Get_PosY()
{
	return PosY;
}

char Screen_Object::Get_Icon()
{
	return Icon;
}

void Screen_Object::Set_ID(int id)
{
	ID = id;
}

void Screen_Object::Set_PosX(int x)
{
	PosX = x;
}

void Screen_Object::Set_PosY(int y)
{
	PosY = y;
}

void Screen_Object::Set_Icon(char icon)
{
	Icon = icon;
}

void Screen_Object::Move(int x, int y)
{
	PosX += x;
	PosY += y;
}