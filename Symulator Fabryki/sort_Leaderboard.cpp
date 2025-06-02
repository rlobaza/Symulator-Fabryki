

#include "sort_Leaderboard.h"
#include "Own_List.h"
#include "Score.h"



void sort_Leaderboard(Own_List<Score*>& Leaderboard)
{

	//Quicksort

    if (Leaderboard.Get_Size() <= 1)
    {
        return;
    }

    Own_List<Score*> Higher;
    Own_List<Score*> Smaller;

    Score* FirstElement = Leaderboard[0];

    for (int i = 1; i < Leaderboard.Get_Size(); i++)
    {
        if (Leaderboard[i]->Get_Money() > FirstElement->Get_Money())
        {
            Higher.Push_Back(Leaderboard[i]);
        }
        else
        {
            Smaller.Push_Back(Leaderboard[i]);
        }
    }

    sort_Leaderboard(Higher);
    sort_Leaderboard(Smaller);


    while (Leaderboard.Get_Size() > 0)
    {
        Leaderboard.Erase(Leaderboard.Get_Size() - 1);
    }


    for (int i = 0; i < Higher.Get_Size(); i++)
    {
        Leaderboard.Push_Back(Higher[i]);
    }
        

    Leaderboard.Push_Back(FirstElement);

    for (int i = 0; i < Smaller.Get_Size(); i++)
    {
        Leaderboard.Push_Back(Smaller[i]);
    }

}