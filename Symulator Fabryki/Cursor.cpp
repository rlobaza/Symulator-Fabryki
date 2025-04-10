#include "Cursor.h" 
#include <iostream>



Cursor::Cursor()
{
	PosX = 1;
	PosY = 1;

	Icon = '^';

	SelX = -1;
	SelY = -1;

	Is_Locked = false;
}

Cursor::~Cursor()
{

}

void Cursor::CursorMoveUp()
{
	if (PosY > 1 && !Is_Locked)
	{
		PosY--;
	}
}

void Cursor::CursorMoveDown()
{
	if (PosY < 20 && !Is_Locked)
	{
		PosY++;
	}
}

void Cursor::CursorMoveLeft()
{
	if (PosX > 1 && !Is_Locked)
	{
		PosX--;
	}
}

void Cursor::CursorMoveRight()
{
	if (PosX < 100 && !Is_Locked)
	{
		PosX++;
	}
}

void Cursor::Select()
{
	Cursor::Lock();

	SelX = PosX;
	SelY = PosY;
}

void Cursor::Unselect()
{
	Cursor::Unlock();

	SelX = -1;
	SelY = -1;
}

void Cursor::Lock()
{
	Is_Locked = true;
	Icon = '*';
}

void Cursor::Unlock()
{
	Is_Locked = false;
	Icon = '^';
}