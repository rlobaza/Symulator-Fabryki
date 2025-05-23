#include "print_Player_Stats.h"
#include "Worker_Container.h"
#include<iostream>
#include<string>

std::string print_Player_Stats(Player& p1, Worker_Container& Workers)
{
	std::string Text;

	Text = Text + "Pieni¹dze: " + std::to_string(p1.Get_Money()) + " PLN" + '\n';
	Text = Text + "Pracownicy: " + std::to_string(Workers.Get_Workers().Get_Size()) + " / " + std::to_string(p1.Get_Max_Workers()) + "\n";
	Text = Text + "Cena Zapakowanego Produktu: " + std::to_string(p1.Get_Packed_Products_Price()) + " PLN" + "\n";

	return Text;
}