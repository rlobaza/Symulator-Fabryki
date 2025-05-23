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

Player::Player(Building_Container& buildings) : Packed_Products_Price(10), Buildings(buildings)
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

void Player::Set_Packed_Products_Price(int param)
{
	Packed_Products_Price = param;
}

void Player::Change_Money(int param)
{
	Money += param;
}

int Player::Get_Money()
{
	return Money;
}

int Player::Get_Packed_Products_Price()
{
	return Packed_Products_Price;
}

void Player::Calculate_Packed_Products_Price()
{
	Packed_Products_Price = 10;

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_Name() == "Control_Laboratory")
		{
			Packed_Products_Price = Packed_Products_Price + (5 * Buildings.Get_Buildings()[i]->Get_Lvl());
		}
	}

}