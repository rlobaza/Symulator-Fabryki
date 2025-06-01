


#include <string>

#include "Score.h"


Score::Score(std::string nickname, std::string date, int money) : Nickname(nickname), Date(date), Money(money)
{

}

Score::~Score()
{

}

void Score::Set_Nickname(std::string nickname)
{
	Nickname = nickname;
}

void Score::Set_Date(std::string date)
{
	Date = date;
}

void Score::Set_Money(int money)
{
	Money = money;
}

std::string Score::Get_Nickname()
{
	return Nickname;
}

std::string Score::Get_Date()
{
	return Date;
}

int Score::Get_Money()
{
	return Money;
}

std::string Score::print_Score()
{
	std::string str = "";

	str = str + Nickname + "    " + Date;

	if (str.size() >= 2)
	{
		str.erase(str.size() - 2); // usuwa 2 ostatnie znaki
	}

	str += "  --->  " + std::to_string(Get_Money());

	return str;
}