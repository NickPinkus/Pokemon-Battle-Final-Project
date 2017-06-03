#pragma once
#include "Monster.h"

class WildPkmn :
	public Monster
{
private:
	int _combatPower;
public:
	Attacks Attack1 = Attacks("Kamehameha", 9001);
	Attacks Attack2 = Attacks("Zergling Rush", 6);

	WildPkmn(string name);
	~WildPkmn();

	void setName(string name);
	int GetCombatPower();
};

