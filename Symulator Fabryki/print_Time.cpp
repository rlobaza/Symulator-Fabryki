
#include <chrono>
#include <iostream>


#include "print_Time.h"


void print_Time()
{
	// Pobierz aktualny czas (liczba sekund od 1970-01-01)
	std::time_t czas = std::time(nullptr);

	// Bufor na wynik
	char buffer[26];  // Musi by� wystarczaj�co du�y, by pomie�ci� wynik

	// U�ywamy ctime_s z przestrzeni globalnej
	if (ctime_s(buffer, sizeof(buffer), &czas) == 0) {
		std::cout << "Aktualny czas: " << buffer << std::endl;
	}
	else {
		std::cerr << "B��d przy pobieraniu czasu!" << std::endl;
	}
}