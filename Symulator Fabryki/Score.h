#pragma once

#include <string>




class Score
{

private:

	std::string Nickname;
	std::string Date;
	int Money;

public:

	Score(std::string, std::string, int);
	~Score();

	void Set_Nickname(std::string);
	void Set_Date(std::string);
	void Set_Money(int);

	std::string Get_Nickname();
	std::string Get_Date();
	int Get_Money();

	std::string print_Score();

};