#pragma once

#include<vector>

#include "Screen.h"
#include "Cursor.h"
#include "Screen_Object.h"
#include "Player.h"
#include "Building_Container.h"
#include "Road_Container.h"
#include "Worker_Container.h"
#include "Clock.h"

#include "Menu.h"

#include "Task.h"
#include "Task_Container.h"

void user_Input_Keys(Screen&, Cursor&, char&, bool&, Player&, Building_Container&, Worker_Container&, Road_Container&, Task_Container&, bool&, Menu&, bool&);
