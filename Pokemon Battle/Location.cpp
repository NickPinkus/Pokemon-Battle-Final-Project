#include "Location.h"



Location::Location(string name, int xCoord, int yCoord) : _name(name), _xCoord(xCoord), _yCoord(yCoord)
{
}


Location::~Location()
{
}

string Location::DisplayLocationInfo()
{
	return _name;
}

string Location::getNewCoordinates(int x, int y)
{
	return (_xCoord + x) + "," + (_yCoord + y);
}
