#pragma once
#include "Attacks.h"

class Monster
{
private:
	string _name;
	int maxHealth,
		monsterID;
public:
	Monster();
	~Monster();

	Attacks Attack1 = Attacks ("Default", 0);
	Attacks Attack2 = Attacks ("Default", 0);

	int Health;

	void SetIDNum(int InputID);
	string GetName();
	void SetInfo();
	int GetMaxHealth();
};

