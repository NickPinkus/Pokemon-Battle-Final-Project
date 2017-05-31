#pragma once
#include <string>
#include <ctime>
using namespace std;

class Attacks
{
private:
	string atkName;
	int attack;
	int attackRounds = 1;

public:
	Attacks(string attackName, int attackDamage);
	Attacks(string attackName, int attackDamage, int attackRounds);
	~Attacks();

	int calculateAttackDamage();
	string GetAttackName();
	void RestoreFurySwipes();
};

