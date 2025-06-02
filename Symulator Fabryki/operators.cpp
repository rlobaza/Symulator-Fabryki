
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>

#include "operators.h"
#include "print_Time.h"
#include "Score.h"
#include "add_Score.h"


std::ofstream& operator<<(std::ofstream& ofs, Score* score)
{
	std::string str = "";

	str = str + score->Get_Nickname();
	str = str + "@";
	str = str + print_Time();
	str = str + "%";
	str = str + std::to_string(score->Get_Money());
	str = str + "\n";

	ofs << str;

	return ofs;
}

Own_List<Score*>& operator>>(std::ifstream& ifs, Own_List<Score*>& Leaderboard)
{
	std::string line;

	while (std::getline(ifs, line))
	{
		std::string Nickname;
		std::string Date;
		std::string Money;

		std::string* which = &Nickname;

		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] != '@' && line[i] != '%')
			{
				(*which) += line[i];
			}
			if (line[i] == '@')
			{
				which = &Date;
			}
			if (line[i] == '%')
			{
				which = &Money;
			}
		}

		Score* ptr = new Score(Nickname, Date, std::stoi(Money));

		add_Score(Leaderboard, ptr);

	}

	return Leaderboard;
}