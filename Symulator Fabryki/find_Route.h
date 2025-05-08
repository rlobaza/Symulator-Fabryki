#pragma once

#include <queue>

#include "Worker.h"
#include "Road.h"
#include "Own_List.h"
#include "Road_Container.h"

void find_Route(Worker*, Building*, Road_Container&, std::queue<Road*>&);