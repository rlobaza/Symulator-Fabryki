

#include <iostream>
#include <fstream>
#include <filesystem>

#include "Own_List.h"
#include "Score.h"
#include "operators.h"





void save_Leaderboard(Own_List<Score*>& Leaderboard)
{
	std::filesystem::create_directories("Data");

	std::ofstream file("Data/Leaderboard.txt");

	if (file.good())
	{

		std::cout << "Zapisywanie..." << std::endl;

		for (int i = 0; i < Leaderboard.Get_Size(); i++)
		{
			file << Leaderboard[i];
		}

		file.close();

		system("cls");

		std::cout << "Zapisywanie zakoñczone sukcesem." << std::endl;
		std::cout << "Wciœnij dowolny klawisz aby wyjœæ." << std::endl;

	}
	else
	{
		std::cout << "Zapisywanie nieudane." << std::endl;

		return;
	}


}