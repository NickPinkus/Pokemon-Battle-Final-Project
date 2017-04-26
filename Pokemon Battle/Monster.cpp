#include "Monster.h"


string Monster::GetName()
{
	return _name;
}

void Monster::SetInfo()
{
	if (monsterID == 0)
	{
		_name = "Bulbasaur";
		Health = 12;
		Attack1 = Attacks("Tackle", 3);
		Attack2 = Attacks("Vine Whip", 5);
	}
	else if (monsterID == 1)
	{
		_name = "Charmander";
		Health = 8;
		Attack1 = Attacks("Scratch", 5);
		Attack2 = Attacks("Ember", 7);
	}
	else if (monsterID == 2)
	{
		_name = "Squirtle";
		Health = 10;
		Attack1 = Attacks("Tackle", 3);
		Attack2 = Attacks("Bubble", 5);
	}
	else if (monsterID == 3)
	{
		_name = "Pikachu";
		Health = 8;
		Attack1 = Attacks("Scratch", 5);
		Attack2 = Attacks("Thundershock", 7);
	}
	else if (monsterID == 4)
	{
		_name = "Eevee";
		Health = 12;
		Attack1 = Attacks("Tackle", 3);
		Attack2 = Attacks("Quick Attack", 5);
	}
	else
	{
		_name = "DEFAULT";
	}

	maxHealth = Health;
}

int Monster::GetMaxHealth()
{
	return maxHealth;
}

Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::SetIDNum(int InputID)
{
	monsterID = InputID;
}
