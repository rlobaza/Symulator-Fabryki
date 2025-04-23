#pragma once
#include "Button.h"




class Load_Game : public Button
{

public:

	Load_Game();
	~Load_Game();

	virtual void Do(bool&, bool&);

};

