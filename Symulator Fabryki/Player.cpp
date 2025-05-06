#include <vector>
#include <iostream>

#include "Player.h"
#include "Screen_Object.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"

#include "Control_Laboratory.h"
#include "Loading_Ramp.h"
#include "Packaging_Area.h"
#include "Production_Hall.h"
#include "Road.h"
#include "Sorting_Area.h"
#include "Staff_Welfare_Area.h"
#include "Warehouse.h"

Player::Player()
{
	Money = 0;
}

Player::~Player()
{

}

void Player::Set_Money(int param)
{
	Money = param;
}

void Player::Change_Money(int param)
{
	Money += param;
}

int Player::Get_Money()
{
	return Money;
}