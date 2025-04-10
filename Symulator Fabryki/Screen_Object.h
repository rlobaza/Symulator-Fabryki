#pragma once


class Screen_Object
{
public:
	int ID;
	static int NumberOfObjects;
	Screen_Object* SelfPointer;

	int PosX;
	int PosY;
	char Icon;

	Screen_Object();
    Screen_Object(int, int, char);
	virtual ~Screen_Object();

	virtual void Move();
	virtual void Simulate();
};
