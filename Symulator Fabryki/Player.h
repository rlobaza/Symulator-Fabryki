#pragma once

#include <vector>

#include "Screen_Object.h"
#include "Screen_Object_Container.h"

class Player
{
public:

	int Money;

	int Workers;
	int Max_Workers;

	int Materials;
	int Max_Materials;

	int Sorted_Materials;
	int Max_Sorted_Materials;

	int Ready_Products;
	int Max_Ready_Products;

	int Packed_Products;
	int Max_Packed_Products;

	Player();
	~Player();

	void ChangeMoney(int);
	void ChangeWorkers(int);
	void ChangeMaterials(int);
	void ChangeSorted_Materials(int);
	void ChangeReady_Products(int);
	void ChangePacked_Products(int);
	void Update_Maxes(Screen_Object_Container&);
};
