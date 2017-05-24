#pragma once
#include "Map.h"
#include "Location.h"
using namespace std;

int MapMovement();
void GoNorth(Map &map, int &routeNumber);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);