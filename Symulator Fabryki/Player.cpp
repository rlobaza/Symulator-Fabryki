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

Player::Player(Building_Container& buildings, std::string nickname) : Packed_Products_Price(10), Buildings(buildings), Nickname(nickname)
{
	Money = 0;
	Packed_Products_Price = 10;
	Max_Workers = 1;
}

Player::~Player()
{

}

void Player::Set_Nickname(std::string nickname)
{
	Nickname = nickname;
}

void Player::Set_Money(int param)
{
	Money = param;
}

void Player::Set_Packed_Products_Price(int param)
{
	Packed_Products_Price = param;
}

void Player::Set_Max_Workers(int param)
{
	Max_Workers = param;
}

void Player::Change_Money(int param)
{
	Money += param;
}

std::string Player::Get_Nickname()
{
	return Nickname;
}

int Player::Get_Money()
{
	return Money;
}

int Player::Get_Packed_Products_Price()
{
	return Packed_Products_Price;
}

int Player::Get_Max_Workers()
{
	return Max_Workers;
}

void Player::Calculate_Packed_Products_Price()
{
	Packed_Products_Price = 10;

	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_Name() == "Control_Laboratory")
		{
			Packed_Products_Price = Packed_Products_Price + (5 * Buildings.Get_Buildings()[i]->Get_Lvl());
		}
	}

}

void Player::Calculate_Max_Workers()
{
	Max_Workers = 1;

	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_Name() == "Staff_Welfare_Area")
		{
			Max_Workers = Max_Workers + (5 * Buildings.Get_Buildings()[i]->Get_Lvl()) - 1;
		}
	}
}