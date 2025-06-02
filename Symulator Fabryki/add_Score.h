#pragma once

#include "Own_List.h"
#include "Score.h"
#include "Player.h"

void add_Score(Own_List<Score*>& Leaderboard, Player& p1);

void add_Score(Own_List<Score*>& Leaderboard, Score* score);