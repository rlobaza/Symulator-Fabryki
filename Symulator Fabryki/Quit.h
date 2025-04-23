#pragma once

#include "Button.h"




class Quit : public Button
{

public:

	Quit();
	~Quit();

	virtual void Do(bool&, bool&);

};

