
#include <string>

#include "Button.h"



Button::Button(std::string n) : Name(n)
{

}

Button::~Button()
{

}

std::string Button::Get_Name()
{
	return Name;
}

void Button::Set_Name(std::string n)
{
	Name = n;
}