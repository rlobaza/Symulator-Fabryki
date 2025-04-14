#pragma once


class Cursor
{

private:

	int PosX;
	int PosY;

	char Icon;

	int SelX;
	int SelY;

	bool Is_Locked;

public:

	Cursor();
	~Cursor();

	int Get_PosX();
	int Get_PosY();
	char Get_Icon();
	int Get_SelX();
	int Get_SelY();
	bool Get_Is_Locked();

	void Set_PosX(int);
	void Set_PosY(int);
	void Set_Icon(char);
	void Set_SelX(int);
	void Set_SelY(int);
	void Set_Is_Locked(bool);

	void CursorMoveUp();
	void CursorMoveDown();
	void CursorMoveLeft();
	void CursorMoveRight();
	void Select();
	void Unselect();
	void Lock();
	void Unlock();
};