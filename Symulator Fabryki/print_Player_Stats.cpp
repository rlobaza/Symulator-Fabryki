#include "print_Player_Stats.h"
#include<iostream>
#include<string>

std::string print_Player_Stats(Player& p1)
{
	std::string Text;

	Text = Text + "Pieniadze: " + std::to_string(p1.Money) + '\n';

	Text = Text + "Pracownicy: " + std::to_string(p1.Workers) + "/" + std::to_string(p1.Max_Workers) + '\n';

	Text = Text + "Materialy: " + std::to_string(p1.Materials) + "/" + std::to_string(p1.Max_Materials) + '\n';

	Text = Text + "Gotowe Produkty: " + std::to_string(p1.Ready_Products) + "/" + std::to_string(p1.Max_Ready_Products) + '\n';

	Text = Text + "Zapakowane Produkty: " + std::to_string(p1.Packed_Products) + "/" + std::to_string(p1.Max_Packed_Products) + '\n';

	return Text;
}