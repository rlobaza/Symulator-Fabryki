#pragma once

#include<vector>

#include "Screen.h"
#include "Cursor.h"
#include "Screen_Object.h"
#include "Player.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"
#include "Task_Container.h"
#include "Clock.h"

void simulation(Screen&, Cursor&, char&, bool&, Player&, Building_Container&, Worker_Container&, Task_Container&, Road_Container&);