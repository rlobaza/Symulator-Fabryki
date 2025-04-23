
#include <string>
#include <iostream>

#include "next_Frame.h"

std::string next_Frame()
{
	std::string str;

	for (int i = 0; i < 100; i++)
	{
		str = str + '\n';
	}

	return str;
}