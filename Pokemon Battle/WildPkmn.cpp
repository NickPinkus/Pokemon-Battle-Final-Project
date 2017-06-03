#include "WildPkmn.h"



WildPkmn::WildPkmn(string name)
{
	setName(name);
}


WildPkmn::~WildPkmn()
{
}

void WildPkmn::setName(string name)
{
	_name = name;
}

int WildPkmn::GetCombatPower()
{
	return _combatPower;
}
