
#include <string>

#include "add_Score.h"
#include "Own_List.h"
#include "Score.h"
#include "Player.h"
#include "print_Time.h"

void add_Score(Own_List<Score*>& Leaderboard, Player& p1)
{

	std::string date = print_Time();


	Leaderboard.Push_Back(new Score(p1.Get_Nickname(), date, p1.Get_Money()));
}

void add_Score(Own_List<Score*>& Leaderboard, Score* score)
{

	Leaderboard.Push_Back(score);
}