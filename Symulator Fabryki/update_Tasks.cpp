


#include "Building_Container.h"
#include "Task_Container.h"
#include "Worker_Container.h"
#include "Task.h"
#include "find_Route.h"





void update_Tasks(Building_Container& Buildings, Task_Container& Tasks, Worker_Container& Workers)
{

	std::scoped_lock lock(Buildings.Get_Mutex(), Tasks.Get_Mutex(), Workers.Get_Mutex());

	while (Tasks.Get_Tasks().Get_Size() < Workers.Get_Workers().Get_Size())
	{

		int number_1;
		int number_2;

		number_1 = Tasks.Get_Tasks().Get_Size();

		for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
		{

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			if (Buildings.Get_Buildings()[i]->Get_Name() == "Loading_Ramp")
			{
				if (Buildings.Get_Buildings()[i]->Get_Materials_Storage_Used() > 0 && (Buildings.Get_Buildings()[i]->Get_Materials_Storage_Used() > Buildings.Get_Buildings()[i]->Get_Materials_Reserved()))
				{
					for (int j = 0; j < Buildings.Get_Buildings().Get_Size(); j++)
					{
						if (Buildings.Get_Buildings()[j]->Get_Name() == "Sorting_Area" || Buildings.Get_Buildings()[j]->Get_Name() == "Warehouse")
						{
							if (Buildings.Get_Buildings()[j]->Get_Materials_Storage() > (Buildings.Get_Buildings()[j]->Get_Materials_Storage_Reserved() + Buildings.Get_Buildings()[j]->Get_Materials_Storage_Used()))
							{
								for (int k = 0; k < Workers.Get_Workers().Get_Size(); k++)
								{
									if (Workers.Get_Workers()[k]->Get_Current_Task() == nullptr)
									{

										Building* from = Buildings.Get_Buildings()[i];
										Building* to = Buildings.Get_Buildings()[j];

										from->Set_Materials_Reserved(from->Get_Materials_Reserved() + 1);
										to->Set_Materials_Storage_Reserved(to->Get_Materials_Storage_Reserved() + 1);

										Tasks.Get_Tasks().Push_Back(new Task("Materials", from, to, Workers.Get_Workers()[k]));
										Workers.Get_Workers()[k]->Set_Current_Task(Tasks.Get_Tasks()[Tasks.Get_Tasks().Get_Size() - 1]);

										goto sorting_area;
									}
								}
							}
						}
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			sorting_area:

			if (Buildings.Get_Buildings()[i]->Get_Name() == "Sorting_Area")
			{
				if (Buildings.Get_Buildings()[i]->Get_Sorted_Materials_Storage_Used() > Buildings.Get_Buildings()[i]->Get_Sorted_Materials_Reserved())
				{
					for (int j = 0; j < Buildings.Get_Buildings().Get_Size(); j++)
					{
						if (Buildings.Get_Buildings()[j]->Get_Name() == "Production_Hall" || Buildings.Get_Buildings()[j]->Get_Name() == "Warehouse")
						{
							if (Buildings.Get_Buildings()[j]->Get_Sorted_Materials_Storage() > (Buildings.Get_Buildings()[j]->Get_Sorted_Materials_Storage_Reserved() + Buildings.Get_Buildings()[j]->Get_Sorted_Materials_Storage_Used()))
							{
								for (int k = 0; k < Workers.Get_Workers().Get_Size(); k++)
								{
									if (Workers.Get_Workers()[k]->Get_Current_Task() == nullptr)
									{

										Building* from = Buildings.Get_Buildings()[i];
										Building* to = Buildings.Get_Buildings()[j];

										from->Set_Sorted_Materials_Reserved(from->Get_Sorted_Materials_Reserved() + 1);
										to->Set_Sorted_Materials_Storage_Reserved(to->Get_Sorted_Materials_Storage_Reserved() + 1);

										Tasks.Get_Tasks().Push_Back(new Task("Sorted_Materials", from, to, Workers.Get_Workers()[k]));
										Workers.Get_Workers()[k]->Set_Current_Task(Tasks.Get_Tasks()[Tasks.Get_Tasks().Get_Size() - 1]);

										goto production_hall;
									}
								}
							}
						}
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		    production_hall:

			if (Buildings.Get_Buildings()[i]->Get_Name() == "Production_Hall")
			{
				if (Buildings.Get_Buildings()[i]->Get_Ready_Products_Storage_Used() > Buildings.Get_Buildings()[i]->Get_Ready_Products_Reserved())
				{
					for (int j = 0; j < Buildings.Get_Buildings().Get_Size(); j++)
					{
						if (Buildings.Get_Buildings()[j]->Get_Name() == "Packaging_Area" || Buildings.Get_Buildings()[j]->Get_Name() == "Warehouse")
						{
							if (Buildings.Get_Buildings()[j]->Get_Ready_Products_Storage() > (Buildings.Get_Buildings()[j]->Get_Ready_Products_Storage_Reserved() + Buildings.Get_Buildings()[j]->Get_Ready_Products_Storage_Used()))
							{
								for (int k = 0; k < Workers.Get_Workers().Get_Size(); k++)
								{
									if (Workers.Get_Workers()[k]->Get_Current_Task() == nullptr)
									{

										Building* from = Buildings.Get_Buildings()[i];
										Building* to = Buildings.Get_Buildings()[j];

										from->Set_Ready_Products_Reserved(from->Get_Ready_Products_Reserved() + 1);
										to->Set_Ready_Products_Storage_Reserved(to->Get_Ready_Products_Storage_Reserved() + 1);

										Tasks.Get_Tasks().Push_Back(new Task("Ready_Products", from, to, Workers.Get_Workers()[k]));
										Workers.Get_Workers()[k]->Set_Current_Task(Tasks.Get_Tasks()[Tasks.Get_Tasks().Get_Size() - 1]);

										goto packaging_area;
									}
								}
							}
						}
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			packaging_area:

			if (Buildings.Get_Buildings()[i]->Get_Name() == "Packaging_Area")
			{
				if (Buildings.Get_Buildings()[i]->Get_Packed_Products_Storage_Used() > Buildings.Get_Buildings()[i]->Get_Packed_Products_Reserved())
				{
					for (int j = 0; j < Buildings.Get_Buildings().Get_Size(); j++)
					{
						if (Buildings.Get_Buildings()[j]->Get_Name() == "Loading_Ramp" || Buildings.Get_Buildings()[j]->Get_Name() == "Warehouse")
						{
							if (Buildings.Get_Buildings()[j]->Get_Packed_Products_Storage() > (Buildings.Get_Buildings()[j]->Get_Packed_Products_Storage_Reserved() + Buildings.Get_Buildings()[j]->Get_Packed_Products_Storage_Used()))
							{
								for (int k = 0; k < Workers.Get_Workers().Get_Size(); k++)
								{
									if (Workers.Get_Workers()[k]->Get_Current_Task() == nullptr)
									{

										Building* from = Buildings.Get_Buildings()[i];
										Building* to = Buildings.Get_Buildings()[j];

										from->Set_Packed_Products_Reserved(from->Get_Packed_Products_Reserved() + 1);
										to->Set_Packed_Products_Storage_Reserved(to->Get_Packed_Products_Storage_Reserved() + 1);

										Tasks.Get_Tasks().Push_Back(new Task("Packed_Products", from, to, Workers.Get_Workers()[k]));
										Workers.Get_Workers()[k]->Set_Current_Task(Tasks.Get_Tasks()[Tasks.Get_Tasks().Get_Size() - 1]);

										goto warehouse;
									}
								}
							}
						}
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			warehouse:

			if (Buildings.Get_Buildings()[i]->Get_Name() == "Warehouse")
			{

			}

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}

		number_2 = Tasks.Get_Tasks().Get_Size();

		if (number_1 == number_2)
		{
			break;
		}

	}
 
	return;

}