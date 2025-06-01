#pragma once
#include "Button.h"




class Leaderboard : public Button
{

public:

	Leaderboard();
	~Leaderboard();

	virtual void Do(bool&, bool&, bool&);


};
