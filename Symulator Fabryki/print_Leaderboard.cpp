
#include "print_Leaderboard.h"
#include "Own_List.h"
#include "Score.h"

std::string print_Leaderboard(Own_List<Score*>& leaderboard)
{
	std::string str = "";

	str += "                             Ranking:";
	str += "\n";
	str += "                             Top 5 z wszystkich " + std::to_string(leaderboard.Get_Size()) + " wyników.";

	str += "\n\n";

	if (leaderboard.Get_Size() > 5)
	{
		for (int i = 0; i < 5; i++)
		{
			str += "                             ";
			str += std::to_string(i + 1) + ". ";
			str += leaderboard[i]->print_Score();
			str += "\n";
		}
	}
	else
	{
		for (int i = 0; i < leaderboard.Get_Size(); i++)
		{
			str += "                             ";
			str += std::to_string(i + 1) + ". ";
			str += leaderboard[i]->print_Score();
			str += "\n";
		}
	}

	return str;
}