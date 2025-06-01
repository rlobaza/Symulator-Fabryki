#pragma once

#include <fstream>

#include "Player.h"
#include "print_Time.h"
#include "Score.h"


std::ofstream& operator<<(std::ofstream& ofs, Score* score);
