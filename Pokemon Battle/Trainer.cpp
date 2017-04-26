#include "Trainer.h"
#include <iostream>
using namespace std;


Trainer::Trainer(string name) : _name(name)
{
}


Trainer::~Trainer()
{
}



string Trainer::GetName()
{
	return _name;
}

