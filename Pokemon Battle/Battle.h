#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Trainer.h"
using namespace std;

struct WildPokemon
{
	string name;
	int combatPower;
};

string randomNameGenerator();
WildPokemon setMonster();
bool captureAttempt(int);
void printMonster(WildPokemon monster);
void WildEncounter(Trainer Player);