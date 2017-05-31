#pragma once
#include "Attacks.h"
#include <iostream>



Attacks::Attacks(string attackName, int attackDamage) : atkName(attackName), attack(attackDamage)
{
}

Attacks::Attacks(string attackName, int attackDamage, int attackRounds) : atkName(attackName), attack(attackDamage), attackRounds(attackRounds)
{
}


Attacks::~Attacks()
{
}

int Attacks::calculateAttackDamage()
{
	srand(time(NULL));


	switch (rand() % 20 + 1)
	{
	case 1:
		cout << "\n\nBut the attack missed...\n\n";
		return 0;
	case 20:
		cout << "\n\nCritical hit!\n\n";
		if (atkName == "Fury Swipes" && attackRounds > 1)
		{
			if (rand() % 10 == 0)
			{
				attackRounds++;
			}
			attackRounds--;
			return attack * 2 + calculateAttackDamage();
		}
		return attack * 2;
	default:
		cout << "\n\nThe attack hit!\n\n";
		if (atkName == "Fury Swipes" && attackRounds > 1)
		{
			if (rand() % 10 == 0)
			{
				attackRounds++;
			}
			attackRounds--;
			return attack + calculateAttackDamage();
		}
		return attack;
	}
}

string Attacks::GetAttackName()
{
	return atkName;
}

void Attacks::RestoreFurySwipes()
{
	attackRounds = 3;
}
