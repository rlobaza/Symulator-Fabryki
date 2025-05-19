


#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"
#include "Task_Container.h"
#include "Cursor.h"
#include "Player.h"
#include "sell_Building.h"
#include "single_Sound.h"

void sell_Building(Cursor& c1, Building_Container& Buildings, Road_Container& Roads, Task_Container& Tasks, Player& p1)
{
	std::scoped_lock lock1(Buildings.Get_Mutex(), Tasks.Get_Mutex());

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_PosX() == c1.Get_SelX() && Buildings.Get_Buildings()[i]->Get_PosY() == c1.Get_SelY())
		{
			if (Buildings.Get_Buildings()[i]->Get_Name() != "Road")
			{
				p1.Change_Money(2 * Buildings.Get_Buildings()[i]->Get_Cost() * Buildings.Get_Buildings()[i]->Get_Lvl() / 3);
				Buildings.Get_Buildings().Erase(i);
				i--;
				single_Sound("Sounds/COINS");
			}
			else
			{

				for (int j = 0; j < Tasks.Get_Tasks().Get_Size(); j++)
				{
					std::queue<Road*> route = Tasks.Get_Tasks()[j]->Get_Who()->Get_Route();

					for (int k = 0; k < Tasks.Get_Tasks()[j]->Get_Who()->Get_Route().size(); k++)
					{
						if (Buildings.Get_Buildings()[i] == route.front())
						{

							while (Tasks.Get_Tasks()[j]->Get_Who()->Get_Route().empty() == false)
							{
								Tasks.Get_Tasks()[j]->Get_Who()->Get_Route().pop();
							}

							Tasks.Get_Tasks()[j]->Get_Who()->Set_Was_Route_Found(false);
							Tasks.Get_Tasks()[j]->Get_Who()->Set_After_First_Target(false);
							Tasks.Get_Tasks()[j]->Get_Who()->Set_Current_Task(nullptr);

							Tasks.Remove_Tasks(j);

							p1.Change_Money(2 * Buildings.Get_Buildings()[i]->Get_Cost() * Buildings.Get_Buildings()[i]->Get_Lvl() / 3);
							Buildings.Get_Buildings().Erase(i);
							i--;
							single_Sound("Sounds/COINS");

							goto tasks;
						}

						route.pop();
					}
				}

				p1.Change_Money(2 * Buildings.Get_Buildings()[i]->Get_Cost() * Buildings.Get_Buildings()[i]->Get_Lvl() / 3);
				Buildings.Get_Buildings().Erase(i);
				i--;
				single_Sound("Sounds/COINS");
			}
		}
	}

	tasks:


	for (int i = 0; i < Tasks.Get_Tasks().Get_Size(); i++)
	{
		if ((Tasks.Get_Tasks()[i]->Get_From()->Get_PosX() == c1.Get_SelX() && Tasks.Get_Tasks()[i]->Get_From()->Get_PosY() == c1.Get_SelY()) || (Tasks.Get_Tasks()[i]->Get_To()->Get_PosX() == c1.Get_SelX() && Tasks.Get_Tasks()[i]->Get_To()->Get_PosY() == c1.Get_SelY()))
		{
			while (Tasks.Get_Tasks()[i]->Get_Who()->Get_Route().empty() == false)
			{
				Tasks.Get_Tasks()[i]->Get_Who()->Get_Route().pop();
			}

			Tasks.Get_Tasks()[i]->Get_Who()->Set_Was_Route_Found(false);
			Tasks.Get_Tasks()[i]->Get_Who()->Set_After_First_Target(false);
			Tasks.Get_Tasks()[i]->Get_Who()->Set_Current_Task(nullptr);

			Tasks.Remove_Tasks(i);

			i--;
		}
	}

	std::lock_guard<std::recursive_mutex> lock2(Roads.Get_Mutex());

	for (int i = 0; i < Roads.Get_Roads().Get_Size(); i++)
	{

		if (Roads.Get_Roads()[i]->Get_PosX() == c1.Get_SelX() && Roads.Get_Roads()[i]->Get_PosY() == c1.Get_SelY())
		{
			delete Roads.Get_Roads()[i];
			Roads.Get_Roads().Erase(i);
			i--;
		}

	}
}