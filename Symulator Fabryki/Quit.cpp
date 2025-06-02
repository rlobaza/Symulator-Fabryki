#include "Quit.h"
#include "single_Sound.h"




Quit::Quit() : Button("Wyjœcie")
{

}

Quit::~Quit()
{

}

void Quit::Do(bool& Gameover, bool& In_Menu, bool& In_Leaderboard)
{
	Gameover = true;
	single_Sound("Sounds/SELECT");
}