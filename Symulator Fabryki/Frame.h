#pragma once

#include <string>


class Frame
{

private:
	std::string Whole_Frame;


public:

	Frame();
	~Frame();

	void Add_To_Frame(std::string);
	void Print_Frame();
	void Clear_Frame();

};
