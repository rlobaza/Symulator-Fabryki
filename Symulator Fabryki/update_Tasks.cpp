


#include "Building_Container.h"
#include "Task_Container.h"
#include "Worker_Container.h"
#include "Task.h"





void update_Tasks(Building_Container& Buildings, Task_Container& Tasks, Worker_Container& Workers)
{

	std::scoped_lock lock(Buildings.Get_Mutex(), Tasks.Get_Mutex(), Workers.Get_Mutex());


	if (Tasks.Get_Tasks().Get_Size() >= Workers.Get_Workers().Get_Size())
	{
		return;
	}

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Buildings.Get_Buildings()[i]->Get_Name() == "Loading_Ramp")
		{
			if (Buildings.Get_Buildings()[i]->Get_Materials_Storage_Used() > 0)
			{
				for (int j = 0; j < Buildings.Get_Buildings().Get_Size(); j++)
				{
					if (Buildings.Get_Buildings()[j]->Get_Name() == "Sorting_Area" || Buildings.Get_Buildings()[j]->Get_Name() == "Warehouse")
					{
						if (Buildings.Get_Buildings()[j]->Get_Materials_Storage_Used() < Buildings.Get_Buildings()[j]->Get_Materials_Storage())
						{
							for (int k = 0; k < Workers.Get_Workers().Get_Size(); k++)
							{
								if (Workers.Get_Workers()[k]->Get_Current_Task() == nullptr)
								{
									Building* Target = Buildings.Get_Buildings()[j];
									Tasks.Get_Tasks().Push_Back(new Task("Materials", Buildings.Get_Buildings()[i], Target, Workers.Get_Workers()[k]));
									Workers.Get_Workers()[k]->Set_Current_Task(Tasks.Get_Tasks()[Tasks.Get_Tasks().Get_Size() - 1]);

									if (Tasks.Get_Tasks().Get_Size() >= Workers.Get_Workers().Get_Size())
									{
										return;
									}
								}
							}
						}
					}
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Buildings.Get_Buildings()[i]->Get_Name() == "Sorting_Area")
		{

		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Buildings.Get_Buildings()[i]->Get_Name() == "Production_Hall")
		{

		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Buildings.Get_Buildings()[i]->Get_Name() == "Packagin_Area")
		{

		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Buildings.Get_Buildings()[i]->Get_Name() == "Warehouse")
		{

		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
 
	return;

}