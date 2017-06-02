#pragma once
#include "Map.h"
#include "Location.h"
#include "Trainer.h"
using namespace std;

void MapMovement(Trainer Player);
void GoNorth(Map &map, int &routeNumber);
void GoSouth(Map &map, int &routeNumber);
void GoEast(Map &map, int &routeNumber);
void GoWest(Map &map, int &routeNumber);