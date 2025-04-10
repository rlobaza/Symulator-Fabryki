#include <iostream>

#include "windows.h"
#include "framerate.h"

double framerate()
{
    DEVMODE devmode;

    // Ustawienie struktury na warto�ci domy�lne
    memset(&devmode, 0, sizeof(devmode));
    devmode.dmSize = sizeof(devmode);

    // Uzyskanie informacji o aktualnym trybie wy�wietlania dla monitora 0 (pierwszy monitor)
    if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devmode))
    {
        return devmode.dmDisplayFrequency;
    }
    else
    {
        return 1;
    }
}