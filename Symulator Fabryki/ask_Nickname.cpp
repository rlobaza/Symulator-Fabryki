
#include <iostream>
#include <string>
#include "ask_Nickname.h"
#include "generate_Empty_Lines.h"


std::string ask_Nickname()
{
	std::string nickname = "";

	bool condition_1 = false;
	bool condition_2 = false;
	bool condition_3 = false;


	while (condition_1 == false || condition_2 == false || condition_3 == false)
	{

		std::cout << "Podaj swój pseudonim: ";

		std::cin >> nickname;

		if (nickname.size() >= 8)
		{
			system("cls");
			std::cout << "Maksymalna d³ugoœæ pseudonimu to 8 znaków." << std::endl;
			condition_1 = false;
		}
		else
		{
			condition_1 = true;
		}

		for (int i = 0; i < nickname.size(); i++)
		{
			if (nickname[i] == '@')
			{
				system("cls");
				std::cout << "U¿yto nieprawid³owego znaku \"@\"." << std::endl;
				condition_2 = false;
			}
			else
			{
				condition_2 = true;
			}

			if (nickname[i] == '%')
			{
				system("cls");
				std::cout << "U¿yto nieprawid³owego znaku \"%\"." << std::endl;
				condition_3 = false;
			}
			else
			{
				condition_3 = true;
			}
		}

	}

	return nickname;
	
}