
#include <iostream>
#include <string>

#include "Frame.h";


Frame::Frame()
{
	Whole_Frame = "";
}

Frame::~Frame()
{

}

void Frame::Add_To_Frame(std::string Addition)
{
	Whole_Frame += '\n' + Addition;
}

void Frame::Print_Frame()
{
	std::cout << Whole_Frame << std::flush;
}

void Frame::Clear_Frame()
{
	Whole_Frame = "";
}