#include "Quit.h"




Quit::Quit() : Button("Wyjœcie")
{

}

Quit::~Quit()
{

}

void Quit::Do(bool& Gameover, bool& In_Menu)
{
	Gameover = true;
}