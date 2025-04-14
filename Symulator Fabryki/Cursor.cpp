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

int Cursor::Get_PosX()
{
	return PosX;
}

int Cursor::Get_PosY()
{
	return PosY;
}

char Cursor::Get_Icon()
{
	return Icon;
}

int Cursor::Get_SelX()
{
	return SelX;
}

int Cursor::Get_SelY()
{
	return SelY;
}

bool Cursor::Get_Is_Locked()
{
	return Is_Locked;
}

void Cursor::Set_PosX(int param)
{
	PosX = param;
}

void Cursor::Set_PosY(int param)
{
	PosY = param;
}

void Cursor::Set_Icon(char param)
{
	Icon = param;
}

void Cursor::Set_SelX(int param)
{
	SelX = param;
}

void Cursor::Set_SelY(int param)
{
	SelY = param;
}

void Cursor::Set_Is_Locked(bool param)
{
	Is_Locked = param;
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