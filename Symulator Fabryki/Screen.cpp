#include <iostream>
#include <string>

#include "Screen.h"


Screen::Screen() //konstruktor
{

    for (int x = 0; x < 102; x++)
    {
        for (int y = 0; y < 22; y++)
        {
            pixels[x][y] = ' ';
        }
    }




    for (int x = 0; x < 102; x++)
    {
        pixels[x][0] = '#';
    }

    for (int y = 0; y < 22; y++)
    {
        pixels[0][y] = '#';
    }

    for (int y = 0; y < 22; y++)
    {
        pixels[101][y] = '#';
    }

    for (int x = 0; x < 102; x++)
    {
        pixels[x][21] = '#';
    }

    pixelSTR.resize(2121);
}

Screen::~Screen() //destruktor
{

}

void Screen::Input(int x, int y, char c) //dodaj do wyswietlenia
{
    if (x >= 0 && x <= 100 && y >= 0 && y <= 20)
    {
        pixels[x][y] = c;
    }

}

void Screen::Output() //wyswietl
{
    for (int y = 0; y < 22; y++)
    {
        for (int x = 0; x < 102; x++)
        {
            pixelSTR = pixelSTR + pixels[x][y];
        }

        pixelSTR = pixelSTR + '\n';
    }

    std::cout << pixelSTR << std::endl;
    std::cout << std::flush;
}

void Screen::Clear() //wyczysc
{

    for (int x = 0; x < 102; x++)
    {
        for (int y = 0; y < 22; y++)
        {
            pixels[x][y] = ' ';
        }
    }




    for (int x = 0; x < 102; x++)
    {
        pixels[x][0] = '#';
    }

    for (int y = 0; y < 22; y++)
    {
        pixels[0][y] = '#';
    }

    for (int y = 0; y < 22; y++)
    {
        pixels[101][y] = '#';
    }

    for (int x = 0; x < 102; x++)
    {
        pixels[x][21] = '#';
    }

    pixelSTR.clear();
}