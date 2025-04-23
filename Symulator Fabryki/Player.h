#pragma once

#include <vector>

#include "Screen_Object.h"
#include "Screen_Object_Container.h"

class Player
{
private:

int Money;

public:

Player();
~Player();

void Set_Money(int);
void Change_Money(int);
int Get_Money();
};
