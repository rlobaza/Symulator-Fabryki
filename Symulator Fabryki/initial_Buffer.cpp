

#include <string>
#include <iostream>

#include "initial_Buffer.h"


void initial_Buffer()
{
	std::string str;

	for (int i = 0; i < 10000; i++)
	{
		str = str + '\n';
	}

	std::cout << str;
}