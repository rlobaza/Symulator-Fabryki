


#include <windows.h>
#include <iostream>

#include "setConsoleSize.h"




void setConsoleSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    if (console == nullptr) return;

    // Ustaw rozmiar bufora konsoli
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Ustaw rozmiar okna konsoli
    SMALL_RECT windowSize = { 0, 0, static_cast<SHORT>(width - 1), static_cast<SHORT>(height - 1) };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}