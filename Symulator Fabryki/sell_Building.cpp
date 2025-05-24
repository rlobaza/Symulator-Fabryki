

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

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++) //sprawdzamy budynki
	{
		if (Buildings.Get_Buildings()[i]->Get_PosX() == c1.Get_SelX() && Buildings.Get_Buildings()[i]->Get_PosY() == c1.Get_SelY()) //jezeli budynek na kursorze
		{
			if (Buildings.Get_Buildings()[i]->Get_Name() == "Road") //jezeli budynek to droga
			{

				for (int j = 0; j < Tasks.Get_Tasks().Get_Size(); j++) //sprawdzamy taski
				{
					std::queue<Road*> route = Tasks.Get_Tasks()[j]->Get_Who()->Get_Route();
					bool to_delete = false;

					for (int k = 0; k < Tasks.Get_Tasks()[j]->Get_Who()->Get_Route().size(); k++) //sprawdzamy trasy w taskach
					{
						if (Buildings.Get_Buildings()[i] == route.front()) //sprawdzamy czy ta droga nie nalezy do jakiejs trasy w tasku
						{

							while (Tasks.Get_Tasks()[j]->Get_Who()->Get_Route().empty() == false) //czyscimy trase
							{
								Tasks.Get_Tasks()[j]->Get_Who()->Get_Route().pop();
							}

							if (Tasks.Get_Tasks()[j]->Get_What() == "Materials") //zerujemy zarezerwowane materialy
							{
								if (Tasks.Get_Tasks()[j]->Get_Who()->Get_After_First_Target() == false)
								{
									Tasks.Get_Tasks()[j]->Get_From()->Set_Materials_Reserved(Tasks.Get_Tasks()[j]->Get_From()->Get_Materials_Reserved() - 1);
									Tasks.Get_Tasks()[j]->Get_To()->Set_Materials_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Materials_Storage_Reserved() - 1);
								}
								else
								{
									Tasks.Get_Tasks()[j]->Get_To()->Set_Materials_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Materials_Storage_Reserved() - 1);
								}
								
							}
							if (Tasks.Get_Tasks()[j]->Get_What() == "Sorted_Materials") //zerujemy zarezerwowane posortowane materialy
							{
								if (Tasks.Get_Tasks()[j]->Get_Who()->Get_After_First_Target() == false)
								{
									Tasks.Get_Tasks()[j]->Get_From()->Set_Sorted_Materials_Reserved(Tasks.Get_Tasks()[j]->Get_From()->Get_Sorted_Materials_Reserved() - 1);
									Tasks.Get_Tasks()[j]->Get_To()->Set_Sorted_Materials_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Sorted_Materials_Storage_Reserved() - 1);
								}
								else
								{
									Tasks.Get_Tasks()[j]->Get_To()->Set_Sorted_Materials_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Sorted_Materials_Storage_Reserved() - 1);
								}

							}
							if (Tasks.Get_Tasks()[j]->Get_What() == "Ready_Products") //zerujemy zarezerwowane gotowe produkty
							{
								if (Tasks.Get_Tasks()[j]->Get_Who()->Get_After_First_Target() == false)
								{
									Tasks.Get_Tasks()[j]->Get_From()->Set_Ready_Products_Reserved(Tasks.Get_Tasks()[j]->Get_From()->Get_Ready_Products_Reserved() - 1);
									Tasks.Get_Tasks()[j]->Get_To()->Set_Ready_Products_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Ready_Products_Storage_Reserved() - 1);
								}
								else
								{
									Tasks.Get_Tasks()[j]->Get_To()->Set_Ready_Products_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Ready_Products_Storage_Reserved() - 1);
								}

							}
							if (Tasks.Get_Tasks()[j]->Get_What() == "Packed_Products") //zerujemy zarezerwowane zapakowane produkty
							{
								if (Tasks.Get_Tasks()[j]->Get_Who()->Get_After_First_Target() == false)
								{
									Tasks.Get_Tasks()[j]->Get_From()->Set_Packed_Products_Reserved(Tasks.Get_Tasks()[j]->Get_From()->Get_Packed_Products_Reserved() - 1);
									Tasks.Get_Tasks()[j]->Get_To()->Set_Packed_Products_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Packed_Products_Storage_Reserved() - 1);
								}
								else
								{
									Tasks.Get_Tasks()[j]->Get_To()->Set_Packed_Products_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Packed_Products_Storage_Reserved() - 1);
								}

							}

							Tasks.Get_Tasks()[j]->Get_Who()->Set_Was_Route_Found(false); //przywracamy pracownika do stanu bez przypisanego taska
							Tasks.Get_Tasks()[j]->Get_Who()->Set_After_First_Target(false);
							Tasks.Get_Tasks()[j]->Get_Who()->Set_Current_Task(nullptr);

							to_delete = true;
						}

						route.pop();
					}

					Tasks.Remove_Tasks(j); //usuwamy wskaznik do usunietego taska
					j--;
				}

				std::lock_guard<std::recursive_mutex> lock2(Roads.Get_Mutex());

				for (int i = 0; i < Roads.Get_Roads().Get_Size(); i++)
				{

					if (Roads.Get_Roads()[i]->Get_PosX() == c1.Get_SelX() && Roads.Get_Roads()[i]->Get_PosY() == c1.Get_SelY())
					{
						Roads.Remove_Roads(i);
						i--;
					}

				}

			}
			else //jezeli ten budynek to nie droga
			{
				for (int j = 0; j < Tasks.Get_Tasks().Get_Size(); j++) //sprawdzamy taski
				{
					//jezeli uzyty jako "from" lub "to" w tym tasku tasku
					if ((Tasks.Get_Tasks()[j]->Get_From()->Get_PosX() == c1.Get_SelX() && Tasks.Get_Tasks()[j]->Get_From()->Get_PosY() == c1.Get_SelY()) || (Tasks.Get_Tasks()[j]->Get_To()->Get_PosX() == c1.Get_SelX() && Tasks.Get_Tasks()[j]->Get_To()->Get_PosY() == c1.Get_SelY()))
					{
						while (Tasks.Get_Tasks()[j]->Get_Who()->Get_Route().empty() == false) //czyscimy trase pracownika
						{
							Tasks.Get_Tasks()[j]->Get_Who()->Get_Route().pop();
						}

						if (Tasks.Get_Tasks()[j]->Get_What() == "Materials") //zerujemy zarezerwowane materialy
						{
							if (Tasks.Get_Tasks()[j]->Get_Who()->Get_After_First_Target() == false)
							{
								Tasks.Get_Tasks()[j]->Get_From()->Set_Materials_Reserved(Tasks.Get_Tasks()[j]->Get_From()->Get_Materials_Reserved() - 1);
								Tasks.Get_Tasks()[j]->Get_To()->Set_Materials_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Materials_Storage_Reserved() - 1);
							}
							else
							{
							    Tasks.Get_Tasks()[j]->Get_To()->Set_Materials_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Materials_Storage_Reserved() - 1);
							}
								
							}
						if (Tasks.Get_Tasks()[j]->Get_What() == "Sorted_Materials") //zerujemy zarezerwowane posortowane materialy
						{
							if (Tasks.Get_Tasks()[j]->Get_Who()->Get_After_First_Target() == false)
							{
								Tasks.Get_Tasks()[j]->Get_From()->Set_Sorted_Materials_Reserved(Tasks.Get_Tasks()[j]->Get_From()->Get_Sorted_Materials_Reserved() - 1);
								Tasks.Get_Tasks()[j]->Get_To()->Set_Sorted_Materials_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Sorted_Materials_Storage_Reserved() - 1);
							}
							else
							{
								Tasks.Get_Tasks()[j]->Get_To()->Set_Sorted_Materials_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Sorted_Materials_Storage_Reserved() - 1);
							}

						}
						if (Tasks.Get_Tasks()[j]->Get_What() == "Ready_Products") //zerujemy zarezerwowane gotowe produkty
						{
							if (Tasks.Get_Tasks()[j]->Get_Who()->Get_After_First_Target() == false)
							{
								Tasks.Get_Tasks()[j]->Get_From()->Set_Ready_Products_Reserved(Tasks.Get_Tasks()[j]->Get_From()->Get_Ready_Products_Reserved() - 1);
								Tasks.Get_Tasks()[j]->Get_To()->Set_Ready_Products_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Ready_Products_Storage_Reserved() - 1);
							}
							else
							{
								Tasks.Get_Tasks()[j]->Get_To()->Set_Ready_Products_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Ready_Products_Storage_Reserved() - 1);
							}

						}
						if (Tasks.Get_Tasks()[j]->Get_What() == "Packed_Products") //zerujemy zarezerwowane zapakowane produkty
						{
							if (Tasks.Get_Tasks()[j]->Get_Who()->Get_After_First_Target() == false)
							{
								Tasks.Get_Tasks()[j]->Get_From()->Set_Packed_Products_Reserved(Tasks.Get_Tasks()[j]->Get_From()->Get_Packed_Products_Reserved() - 1);
								Tasks.Get_Tasks()[j]->Get_To()->Set_Packed_Products_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Packed_Products_Storage_Reserved() - 1);
							}
							else
							{
								Tasks.Get_Tasks()[j]->Get_To()->Set_Packed_Products_Storage_Reserved(Tasks.Get_Tasks()[j]->Get_To()->Get_Packed_Products_Storage_Reserved() - 1);
							}

						}

						Tasks.Get_Tasks()[j]->Get_Who()->Set_Was_Route_Found(false); //przywracamy pracownika do stanu bez przypisanego taska
						Tasks.Get_Tasks()[j]->Get_Who()->Set_After_First_Target(false);
						Tasks.Get_Tasks()[j]->Get_Who()->Set_Current_Task(nullptr);

						delete Tasks.Get_Tasks()[j]; //usuwamy obiekt taska

						Tasks.Remove_Tasks(j); //usuwamy wskaznik do usunietego taska

						j--;
					}
				}
			}

			p1.Change_Money(2 * Buildings.Get_Buildings()[i]->Get_Cost() * Buildings.Get_Buildings()[i]->Get_Lvl() / 3); //gracz odzyskuje czesc pieniedzy
			delete Buildings.Get_Buildings()[i]; //usuwamy obiekt budynku
			Buildings.Get_Buildings().Erase(i); //usuwamy wskaznik na usuniety budynek
			single_Sound("Sounds/COINS");
			return;
		}
	}
}