#include "New_Game.h"
#include "single_Sound.h"




New_Game::New_Game() : Button("Nowa Gra")
{

}

New_Game::~New_Game()
{

}

void New_Game::Do(bool& Gameover, bool& In_Menu, bool& In_Leaderboard)
{
	In_Menu = false;
	single_Sound("Sounds/SELECT");
}