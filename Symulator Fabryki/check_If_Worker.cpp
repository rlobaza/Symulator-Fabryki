


#include "check_If_Worker.h"


bool check_If_Worker(int x, int y, Worker_Container& Workers)
{
	std::lock_guard<std::recursive_mutex> lock(Workers.Get_Mutex());

	for (int i = 0; i < Workers.Get_Workers().Get_Size(); i++)
	{
		if (Workers.Get_Workers()[i]->Get_PosX() == x && Workers.Get_Workers()[i]->Get_PosY() == y)
		{
			return true;
		}
	}

	return false;
}