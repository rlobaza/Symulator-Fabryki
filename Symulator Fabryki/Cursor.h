#pragma once


class Cursor
{
public:
	int PosX;
	int PosY;

	char Icon;

	int SelX;
	int SelY;

	bool Is_Locked;


	Cursor();
	~Cursor();

	void CursorMoveUp();
	void CursorMoveDown();
	void CursorMoveLeft();
	void CursorMoveRight();
	void Select();
	void Unselect();
	void Lock();
	void Unlock();
};