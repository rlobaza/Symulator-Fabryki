
#include <iostream>
#include <string>
#include "ask_Nickname.h"
#include "generate_Empty_Lines.h"


std::string ask_Nickname()
{
	std::string nickname = "";

	std::cout << "Podaj swój pseudonim: ";
	
	std::cin >> nickname;

	return nickname;
	
}