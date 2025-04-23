#pragma once



#include "Own_List.h"
#include "Button.h"


class Menu
{

private:

	int Size;
	Own_List<Button*> Buttons;
	Button* Selected_Button;
	int Selected_Button_Number;

public:

	Menu();
	~Menu();

	void Set_Size(int);

	int Get_Size();
	Own_List<Button*>& Get_Buttons();
	Button* Get_Selected_Button();
	int Get_Selected_Button_Number();

	void Add_Button(Button*);
	void Selected_Button_Up();
	void Selected_Button_Down();
	std::string Print_Menu();
};

