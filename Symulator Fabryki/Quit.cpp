#include "Quit.h"
#include "single_Sound.h"




Quit::Quit() : Button("Wyj�cie")
{

}

Quit::~Quit()
{

}

void Quit::Do(bool& Gameover, bool& In_Menu, bool& In_Leaderboard)
{
	if (Get_Name() == "Zapisz i Wyjd�")
	{

	}
	Gameover = true;
	Set_Name("Zapisz Wynik i Wyjd�");
	single_Sound("Sounds/SELECT");
}