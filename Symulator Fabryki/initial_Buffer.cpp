

#include <string>
#include <iostream>

#include "initial_Buffer.h"


void initial_Buffer(int param)
{
	std::string str;

	for (int i = 0; i < param; i++)
	{
		str = str + '\n';
	}

	std::cout << str;
}