
#include <chrono>
#include <iostream>


#include "print_Time.h"


std::string print_Time()
{
	std::string str = "";

	// Pobierz aktualny czas (liczba sekund od 1970-01-01)
	std::time_t czas = std::time(nullptr);

	// Bufor na wynik
	char buffer[26];  // Musi byæ wystarczaj¹co du¿y, by pomieœciæ wynik

	// U¿ywamy ctime_s z przestrzeni globalnej
	if (ctime_s(buffer, sizeof(buffer), &czas) == 0)
	{
		str = str + buffer;
	}
	else
	{
		str = str + "B³¹d przy pobieraniu czasu!";
	}

	if (str.size() >= 2)
	{
		for (int i = 0; i < 2; i++)
		{
			str.erase(str.size() - 1);
		}
	}


	return str;
}