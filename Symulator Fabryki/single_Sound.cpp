
#include <windows.h>
#include <mmsystem.h>
#include <string>

#include "single_Sound.h"

#pragma comment(lib, "winmm.lib")

void single_Sound(std::string str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
    std::wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);

    PlaySound(wstr.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}