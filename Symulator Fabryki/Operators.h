#pragma once

#include <fstream>

#include "Player.h"
#include "print_Time.h"
#include "Score.h"


std::ofstream& operator<<(std::ofstream& fs, Score* score);

Own_List<Score*>& operator>>(std::ifstream& ifs, Own_List<Score*>& Leaderboard);


