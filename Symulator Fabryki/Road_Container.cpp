
#include <mutex>


#include "Road.h"
#include "Road_Container.h"



Road_Container::Road_Container()
{
	
}

Road_Container::~Road_Container()
{

}

void Road_Container::Add_Roads(Road* ptr)
{
	Roads.Push_Back(ptr);
	Find_Connected();
}

void Road_Container::Remove_Roads(int param)
{
	Roads.Erase(param);
	Find_Connected();
}

void Road_Container::Find_Connected()
{
	Get_Mutex().lock();

	for (int n = 0; n < Roads.Get_Size(); n++)
	{

		for (int i = 0; i < Roads[n]->Get_Connected().Get_Size(); i++)
		{
			Roads[n]->Get_Connected().Erase(i);
			i--;
		}


		for (int i = 0; i < Roads.Get_Size(); i++)
		{

			if ((Roads[n]->Get_PosX() == Roads[i]->Get_PosX() + 1) || (Roads[n]->Get_PosX() == Roads[i]->Get_PosX() - 1))
			{
				if (Roads[n]->Get_PosY() == Roads[i]->Get_PosY())
				{
					Roads[n]->Get_Connected().Push_Back(Roads[i]);
				}
			}

			if ((Roads[n]->Get_PosY() == Roads[i]->Get_PosY() + 1) || (Roads[n]->Get_PosY() == Roads[i]->Get_PosY() - 1))
			{
				if (Roads[n]->Get_PosX() == Roads[i]->Get_PosX())
				{
					Roads[n]->Get_Connected().Push_Back(Roads[i]);
				}
			}

		}

	}

	Get_Mutex().unlock();

}

Own_List<Road*>& Road_Container::Get_Roads()
{
	return Roads;
}

std::recursive_mutex& Road_Container::Get_Mutex()
{
	return mtx;
}