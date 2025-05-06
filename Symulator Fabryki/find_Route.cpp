

#include <queue>

#include "find_Route.h"
#include "Worker.h"
#include "Road.h"
#include "Own_List.h"
#include "Road_Container.h"

void find_Route(Worker* worker, Building* building, Road_Container& Roads, std::queue<char>& Route)
{
	std::queue<Road*> To_Check;

	for (int i = 0; i < Roads.Get_Roads().Get_Size(); i++)
	{
		if (worker->Get_PosX() == Roads.Get_Roads()[i]->Get_PosX() + 1 || worker->Get_PosX() == Roads.Get_Roads()[i]->Get_PosX() - 1)
		{
			if (worker->Get_PosY() == Roads.Get_Roads()[i]->Get_PosY())
			{

			}
		}

		if (worker->Get_PosY() == Roads.Get_Roads()[i]->Get_PosY() + 1 || worker->Get_PosY() == Roads.Get_Roads()[i]->Get_PosY() - 1)
		{
			if (worker->Get_PosX() == Roads.Get_Roads()[i]->Get_PosX())
			{

			}
		}
	}
}