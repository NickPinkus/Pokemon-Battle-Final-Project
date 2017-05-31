#pragma once
#include "Map.h"
#include "Location.h"
using namespace std;

int MapMovement();
void GoNorth(Map &map, int &routeNumber);
void GoSouth(Map &map, int &routeNumber);
void GoEast(Map &map, int &routeNumber);
void GoWest(Map &map, int &routeNumber);