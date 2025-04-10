#include <vector>
#include <iostream>

#include "Player.h"
#include "Screen_Object.h"
#include "Screen_Object_Container.h"

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

	Workers = 0;
	Max_Workers = 0;

	Materials = 0;
	Max_Materials = 0;

	Sorted_Materials = 0;
	Max_Sorted_Materials = 0;

	Ready_Products = 0;
	Max_Ready_Products = 0;

	Packed_Products = 0;
	Max_Packed_Products = 0;
}

Player::~Player()
{

}

void Player::ChangeMoney(int amount)
{
	Money = Money + amount;
}
void Player::ChangeWorkers(int number)
{
	Workers = Workers + number;
}

void Player::ChangeMaterials(int amount)
{
	Materials = Materials + amount;
}

void Player::ChangeSorted_Materials(int amount)
{
	Sorted_Materials = Sorted_Materials + amount;
}

void Player::ChangeReady_Products(int amount)
{
	Ready_Products = Ready_Products + amount;
}

void Player::ChangePacked_Products(int amount)
{
	Packed_Products = Packed_Products + amount;
}

void Player::Update_Maxes(Screen_Object_Container& Container)
{
	Max_Materials = 0;
	Max_Sorted_Materials = 0;
	Max_Ready_Products = 0;
	Max_Packed_Products = 0;

	/*Screen_Object* Pointer;

	for (int i = 0; i < Screen_Objects.size(); i++)
	{
		Pointer = &Screen_Objects[i];

		if (Screen_Objects[i].Icon == 'W')
		{
			if (Warehouse* warehouse = dynamic_cast<Warehouse*>(Pointer))
			{
				Max_Materials = Max_Materials + warehouse->Materials_Storage;
				Max_Sorted_Materials = Max_Sorted_Materials + warehouse->Sorted_Materials_Storage;
				Max_Ready_Products = Max_Ready_Products + warehouse->Ready_Products_Storage;
				Max_Packed_Products = Max_Packed_Products + warehouse->Packed_Products_Storage;
			}
		}

	}*/

	for (int i = 0; i < Container.Get_Warehouses().size(); i++)
	{
		Max_Materials = Max_Materials + Container.Get_Warehouses()[i].Get_Materials_Storage();
		Max_Sorted_Materials = Max_Sorted_Materials + Container.Get_Warehouses()[i].Get_Sorted_Materials_Storage();
		Max_Ready_Products = Max_Ready_Products + Container.Get_Warehouses()[i].Get_Ready_Products_Storage();
		Max_Packed_Products = Max_Packed_Products + Container.Get_Warehouses()[i].Get_Packed_Products_Storage();
	}
}