#pragma once

#include <vector>

#include "Screen_Object.h"
#include "Building_Container.h"

class Player
{
private:

std::string Nickname;
int Money;
int Packed_Products_Price;
int Max_Workers;

Building_Container& Buildings;

public:

Player(Building_Container&, std::string);
~Player();

void Set_Nickname(std::string);
void Set_Money(int);
void Set_Packed_Products_Price(int);
void Set_Max_Workers(int);
void Change_Money(int);
std::string Get_Nickname();
int Get_Money();
int Get_Packed_Products_Price();
int Get_Max_Workers();
void Calculate_Packed_Products_Price();
void Calculate_Max_Workers();
};
