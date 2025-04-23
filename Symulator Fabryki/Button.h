#pragma once

#include <string>


class Button
{

private:

	std::string Name;

public:

	Button(std::string);
	~Button();

	std::string Get_Name();
	void Set_Name(std::string);

	virtual void Do(bool&, bool&) = 0;

};

