



#include <string>

#include "print_Selected.h"
#include "Building_Container.h"
#include "Cursor.h";

#include "Control_Laboratory.h"
#include "Loading_Ramp.h"
#include "Packaging_Area.h"
#include "Production_Hall.h"
#include "Road.h"
#include "Sorting_Area.h"
#include "Staff_Welfare_Area.h"
#include "Warehouse.h"


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

	if (str == "" && c1.Get_Is_Locked() == false)
	{
		str = str + "q -> Menu G³ówne" + '\n';
		str = str + '\n';
		str = str + "e -> Zaznacz: X " + std::to_string(c1.Get_PosX()) + ", Y " + std::to_string(c1.Get_PosY()) + '\n';
		str = str + "w, s, a, d -> Kursor" + '\n';
		str = str + '\n';
		str = str + "- -> Zwolnij Pracownika" + '\n';
		str = str + "\n\n\n\n\n\n";
	}

	if (str == "" && c1.Get_Is_Locked() == true)
	{
		str = str + "q -> Menu G³ówne" + '\n';
		str = str + '\n';
		str = str + "e -> Odznacz: X " + std::to_string(c1.Get_SelX()) + ", Y " + std::to_string(c1.Get_SelY()) + '\n';
		str = str + '\n';
		str = str + "1 -> Laboratorium Kontrolne: -" + std::to_string(Control_Laboratory::Cost) + " PLN" + '\n';
		str = str + "2 -> Rampa Za³adunkowa: -" + std::to_string(Loading_Ramp::Cost) + " PLN" + '\n';
		str = str + "3 -> Strefa Pakowania: -" + std::to_string(Packaging_Area::Cost) + " PLN" + '\n';
		str = str + "4 -> Hala Produkcyjna: -" + std::to_string(Production_Hall::Cost) + " PLN" + '\n';
		str = str + "5 -> Droga: -" + std::to_string(Road::Cost) + " PLN" + '\n';
		str = str + "6 -> Sortownia: -" + std::to_string(Sorting_Area::Cost) + " PLN" + '\n';
		str = str + "7 -> Zaplecze Socjalne: -" + std::to_string(Staff_Welfare_Area::Cost) + " PLN" + '\n';
		str = str + "8 -> Magazyn: -" + std::to_string(Warehouse::Cost) + " PLN" + '\n';
	}

	return str;
}