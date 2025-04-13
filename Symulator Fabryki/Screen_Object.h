#pragma once


class Screen_Object
{

protected:

	int ID;
	int PosX;
	int PosY;
	char Icon;



public:

	Screen_Object();
	virtual ~Screen_Object();

	virtual int Get_ID();
	virtual int Get_PosX();
	virtual int Get_PosY();
	virtual char Get_Icon() = 0;

	virtual void Set_ID(int);
	virtual void Set_PosX(int);
	virtual void Set_PosY(int);
	virtual void Set_Icon(char);


	virtual void Move(int, int);
	virtual void Simulate() = 0;
};
