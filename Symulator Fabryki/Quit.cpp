#include "Quit.h"




Quit::Quit() : Button("Wyj�cie")
{

}

Quit::~Quit()
{

}

void Quit::Do(bool& Gameover, bool& In_Menu)
{
	Gameover = true;
}