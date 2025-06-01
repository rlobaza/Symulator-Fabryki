#include "Leaderboard.h"
#include "single_Sound.h"




Leaderboard::Leaderboard() : Button("Ranking")
{

}

Leaderboard::~Leaderboard()
{

}

void Leaderboard::Do(bool& Gameover, bool& In_Menu, bool& In_Leaderboard)
{
	In_Leaderboard = true;
	single_Sound("Sounds/SELECT");
}