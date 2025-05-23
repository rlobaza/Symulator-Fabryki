#pragma once

#include <vector>

#include "Screen_Object.h"
#include "Building_Container.h"

class Player
{
private:

int Money;
int Packed_Products_Price;

Building_Container& Buildings;

public:

Player(Building_Container&);
~Player();

void Set_Money(int);
void Set_Packed_Products_Price(int);
void Change_Money(int);
int Get_Money();
int Get_Packed_Products_Price();
void Calculate_Packed_Products_Price();
};
