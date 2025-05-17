


#include "find_Target.h"
#include "Building.h"
#include "Building_Container.h"

Building* find_Target(Building_Container& Buildings)
{
	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_Is_Ready() == true)
		{
			return Buildings.Get_Buildings()[i];
		}
	}
	return nullptr;
}