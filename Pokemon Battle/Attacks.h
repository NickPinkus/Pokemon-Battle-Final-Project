#pragma once
#include <string>
#include <ctime>
using namespace std;

class Attacks
{
private:
	string atkName;
	int attack;

public:
	Attacks(string attackName, int attackDamage);
	~Attacks();

	int calculateAttackDamage();
	string GetAttackName();
};

