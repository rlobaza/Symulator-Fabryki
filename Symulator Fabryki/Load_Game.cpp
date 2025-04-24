#include "Load_Game.h"
#include "single_Sound.h"




Load_Game::Load_Game() : Button("Wczytaj")
{

}

Load_Game::~Load_Game()
{

}

void Load_Game::Do(bool& Gameover, bool& In_Menu)
{
	single_Sound("Sounds/SELECT");
}