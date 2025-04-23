
#include <string>

#include "generate_Empty_Lines.h"



std::string generate_Empty_Lines(int param)
{
	std::string str;

	for (int i = 0; i < param; i++)
	{
		str = str + '\n';
	}

	return str;
}