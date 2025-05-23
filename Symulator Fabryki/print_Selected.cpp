



#include <string>

#include "print_Selected.h"
#include "Building_Container.h"
#include "Cursor.h";


std::string print_Selected(Building_Container& Buildings, Cursor& c1)
{
	std::lock_guard<std::recursive_mutex> lock(Buildings.Get_Mutex());

	std::string str = "";

	for (int i = 0; i < Buildings.Get_Buildings().Get_Size(); i++)
	{
		if (Buildings.Get_Buildings()[i]->Get_PosX() == c1.Get_SelX() && Buildings.Get_Buildings()[i]->Get_PosY() == c1.Get_SelY())
		{
			str = str + Buildings.Get_Buildings()[i]->Stats_String(i);
		}
	}

	if (str == "")
	{
		str = "\n\n\n\n\n\n\n\n\n\n";
	}

	return str;
}