#include "print_Player_Stats.h"
#include<iostream>
#include<string>

std::string print_Player_Stats(Player& p1)
{
	std::string Text;

	Text = Text + "Pieniadze: " + std::to_string(p1.Get_Money()) + '\n';

	return Text;
}