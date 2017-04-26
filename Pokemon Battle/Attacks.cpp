#pragma once
#include "Attacks.h"
#include <iostream>



Attacks::Attacks(string attackName, int attackDamage) : atkName(attackName), attack(attackDamage)
{
}


Attacks::~Attacks()
{
}

int Attacks::calculateAttackDamage()
{
	srand(time(NULL));

	switch (rand() % 5 + 1)
	{
	case 1:
		cout << "\n\nBut the attack missed...\n\n";
		return 0;
	case 5:
		cout << "\n\nCritical hit!\n\n";
		return attack * 2;
	default:
		cout << "\n\nThe attack hit!\n\n";
		return attack;
	}
}

string Attacks::GetAttackName()
{
	return atkName;
}
