#pragma once
#include "Button.h"




class New_Game : public Button
{

public:

	New_Game();
	~New_Game();

	virtual void Do(bool&, bool&, bool&);


};

