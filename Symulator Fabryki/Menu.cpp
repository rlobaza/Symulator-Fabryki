#include "Menu.h"
#include "Button.h"
#include "Own_List.h"
#include "New_Game.h"
#include "Load_Game.h"
#include "Quit.h"




Menu::Menu()
{
	Size = 0;
	Selected_Button_Number = 0;

	Buttons.Push_Back(new New_Game);
	Buttons.Push_Back(new Load_Game);
	Buttons.Push_Back(new Quit);

	Selected_Button = Buttons[0];

	Size = Buttons.Get_Size();
}

Menu::~Menu()
{
	
}

void Menu::Set_Size(int s)
{
	Size = s;
}

int Menu::Get_Size()
{
	return Size;
}

Own_List<Button*>& Menu::Get_Buttons()
{
	return Buttons;
}

Button* Menu::Get_Selected_Button()
{
	Button* btn = Buttons[Get_Selected_Button_Number()];

	return btn;
}

int Menu::Get_Selected_Button_Number()
{
	return Selected_Button_Number;
}

void Menu::Add_Button(Button* btn)
{
	Buttons.Push_Back(btn);
}

void Menu::Selected_Button_Up()
{
	if (Selected_Button_Number - 1 >= 0)
	{
		Selected_Button_Number--;
	}
}

void Menu::Selected_Button_Down()
{
	if (Selected_Button_Number + 1 < Size)
	{
		Selected_Button_Number++;
	}
}

std::string Menu::Print_Menu()
{
	std::string str = "";

	for (int i = 0; i < Size; i++)
	{

		if (i == Get_Selected_Button_Number())
		{
			str = str + "                                                     -> " + Get_Buttons()[i]->Get_Name() + "\n";
		}
		
		if (i != Get_Selected_Button_Number())
		{
			str = str + "                                                        " + Get_Buttons()[i]->Get_Name() + "\n";
		}

	}

	return str;
}