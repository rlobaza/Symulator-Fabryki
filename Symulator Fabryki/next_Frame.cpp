
#include <string>
#include <iostream>

#include "next_Frame.h"

void next_Frame()
{
	std::string str;

	for (int i = 0; i < 50; i++)
	{
		str = str + '\n';
	}

	std::cout << str;
}