#include "Quit.h"
#include "single_Sound.h"




Quit::Quit() : Button("Wyjúcie")
{

}

Quit::~Quit()
{

}

void Quit::Do(bool& Gameover, bool& In_Menu, bool& In_Leaderboard)
{
	if (Get_Name() == "Zapisz i Wyjdü")
	{

	}
	Gameover = true;
	Set_Name("Zapisz Wynik i Wyjdü");
	single_Sound("Sounds/SELECT");
}