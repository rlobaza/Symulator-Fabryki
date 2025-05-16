

#include <queue>
#include <stack>
#include <iostream>

#include "find_Route.h"
#include "Worker.h"
#include "Road.h"
#include "Own_List.h"
#include "Road_Container.h"

void find_Route(Worker* worker, Building* building, Road_Container& Roads, std::queue<Road*>& Route)
{

	for (int i = 0; i < Route.size(); i++)
	{
		Route.pop();
	}

	Road* start = nullptr;

	std::queue<Road*> To_Check;

	for (int i = 0; i < Roads.Get_Roads().Get_Size(); i++)
	{
		if (Roads.Get_Roads()[i]->Get_PosX() == worker->Get_PosX() && Roads.Get_Roads()[i]->Get_PosY() == worker->Get_PosY())
		{
			start = Roads.Get_Roads()[i];
		}
	}

	if (nullptr)
	{
		return;
	}

	To_Check.push(start);

	Road* Actuall = To_Check.front();

	start->Set_Distance(0);
	start->Set_Is_Visited(true);



	while (To_Check.size() != 0)
	{
		Actuall = To_Check.front();
		Actuall->Set_Is_Visited(true);
		To_Check.pop();


		if (
			(((Actuall->Get_PosX() == building->Get_PosX() + 1) || (Actuall->Get_PosX() == building->Get_PosX() - 1)) && Actuall->Get_PosY() == building->Get_PosY())
			|| (((Actuall->Get_PosY() == building->Get_PosY() + 1) || (Actuall->Get_PosY() == building->Get_PosY() - 1)) && Actuall->Get_PosX() == building->Get_PosX()))
		{

			std::stack<Road*> stck;

			while (Actuall != start)
			{
				stck.push(Actuall);
				Actuall = Actuall->Get_Previous();
			}

			while (stck.empty() == false)
			{
				Route.push(stck.top());
				stck.pop();
			}


			for (int i = 0; i < Roads.Get_Roads().Get_Size(); i++)
			{
				Roads.Get_Roads()[i]->Set_Distance(999);
				Roads.Get_Roads()[i]->Set_Is_Added(false);
				Roads.Get_Roads()[i]->Set_Is_Visited(false);
				Roads.Get_Roads()[i]->Set_Previous(nullptr);
			}


			return;
		}

		for (int i = 0; i < Actuall->Get_Connected().Get_Size(); i++)
		{
			if (Actuall->Get_Distance() + 1 < Actuall->Get_Connected()[i]->Get_Distance())
			{
				Actuall->Get_Connected()[i]->Set_Previous(Actuall);
				Actuall->Get_Connected()[i]->Set_Distance(Actuall->Get_Distance() + 1);
			}

			if (Actuall->Get_Connected()[i]->Get_Is_Visited() == false && Actuall->Get_Connected()[i]->Get_Is_Added() == false)
			{
				To_Check.push(Actuall->Get_Connected()[i]);
				Actuall->Get_Connected()[i]->Set_Is_Added(true);
			}
		}

	}

	for (int i = 0; i < Roads.Get_Roads().Get_Size(); i++)
	{
		Roads.Get_Roads()[i]->Set_Distance(999);
		Roads.Get_Roads()[i]->Set_Is_Added(false);
		Roads.Get_Roads()[i]->Set_Is_Visited(false);
		Roads.Get_Roads()[i]->Set_Previous(nullptr);
	}

	return;
}