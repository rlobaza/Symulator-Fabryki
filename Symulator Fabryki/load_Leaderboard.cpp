

#include <fstream>
#include <string>
#include <iostream>

#include "load_Leaderboard.h"
#include "Own_List.h"
#include "Score.h"
#include "add_Score.h"
#include "operators.h"




void load_Leaderboard(Own_List<Score*>& Leaderboard)
{

	std::ifstream file("Data/Leaderboard.txt", std::ios::in);

	if (file.good())
	{
		
		file >> Leaderboard;

		file.close();

	}
	else
	{
		return;
	}


}