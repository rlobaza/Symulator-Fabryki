


#include "operators.h"
#include "print_Time.h"
#include "Score.h"


std::ofstream& operator<<(std::ofstream& ofs, Score* score)
{
	std::string str = "";

	str = str + score->Get_Nickname();
	str = str + "@";
	str = str + print_Time();

	if (str.size() >= 2)
	{
		str.erase(str.size() - 2); // usuwa 2 ostatnie znaki
	}

	str = str + "@";

	str = str + std::to_string(score->Get_Money());

	str = str + "\n";

	ofs << str;

	return ofs;
}