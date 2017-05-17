#include "Map.h"



Map::Map(string startLocationName)
{
	CurrentLocation = new Location(startLocationName, 0, 0);
	_locationsVisited.push(CurrentLocation);
	_HowDidIGetHere.push(CurrentLocation);
	string hash = "(0,0)";
	_mapLookup[hash] = CurrentLocation;
	HomePointer = CurrentLocation;
}


Map::~Map()
{
}

void Map::Move(Location *newLocation) 
{	
	_locationsVisited.push(newLocation);
	_HowDidIGetHere.push(newLocation);
	CurrentLocation = newLocation;
}

Location * Map::LookupLocationOnMap(int x, int y)
{
	string hash = "(" + to_string(x) + "," + to_string(y) + ")";
	return _mapLookup[hash];
}

void Map::AddToMap(string coordinates, Location * locationPtr)
{
	_mapLookup[coordinates] = locationPtr;
}

string Map::HowDidIGetHere()
{
	string result = "How you got here:\n";
	while (_HowDidIGetHere.size() != 0)
	{
		result += _HowDidIGetHere.front()->DisplayLocationInfo();
		_HowDidIGetHere.pop();
		_locationsVisited.pop(); //Clearing the stack since we are returning home
	}

	result += "\nReturning Home....\n";
	CurrentLocation = HomePointer;

	return result;
}

string Map::GetPathBackToHome()
{
	string result = "Path back to Home:\n";

	while (_locationsVisited.size() != 0)
	{
		result += _locationsVisited.top()->DisplayLocationInfo();
		_locationsVisited.pop();
		_HowDidIGetHere.pop(); //Clearing the queue since we are returning home
	}

	result += "\nReturning Home....\n";

	CurrentLocation = HomePointer;

	return result;
}
