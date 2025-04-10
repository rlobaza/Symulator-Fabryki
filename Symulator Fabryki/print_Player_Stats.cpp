#include "print_Player_Stats.h"
#include<iostream>
#include<string>

void print_Player_Stats(Player& p1)
{
	std::string Text;

	Text = "Pieniadze: ";
	std::cout << Text;
	Text = std::to_string(p1.Money);
	std::cout << Text << std::endl;

	Text = "Pracownicy: ";
	std::cout << Text;
	Text = std::to_string(p1.Workers) + "/" + std::to_string(p1.Max_Workers);
	std::cout << Text << std::endl;

	Text = "Materialy: ";
	std::cout << Text;
	Text = std::to_string(p1.Materials) + "/" + std::to_string(p1.Max_Materials);
	std::cout << Text << std::endl;

	Text = "Gotowe Produkty: ";
	std::cout << Text;
	Text = std::to_string(p1.Ready_Products) + "/" + std::to_string(p1.Max_Ready_Products);
	std::cout << Text << std::endl;

	Text = "Zapakowane Produkty: ";
	std::cout << Text;
	Text = std::to_string(p1.Packed_Products) + "/" + std::to_string(p1.Max_Packed_Products);
	std::cout << Text << std::endl;
}