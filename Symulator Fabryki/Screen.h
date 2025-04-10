#pragma once

#include<string>


class Screen
{

public:

	char pixels[102][22]; 
	std::string pixelSTR;


public:

	Screen(); //konstruktor

	~Screen(); //destruktor

	void Input(int, int, char); //dodaj do wyswietlenia

	void Output(); //wyswietl

	void Clear(); //wyczysc


};
