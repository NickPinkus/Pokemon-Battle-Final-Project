#include "Map.h"



Map::Map(string startLocationName)
{
	CurrentLocation = new Location(startLocationName, 0, 0);
	_locationsVisited.push(CurrentLocation);
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


string Map::GetPathBackToHome()
{
	string result = "Path back to Pallet Town:\n";

	while (_locationsVisited.size() != 0)
	{
		result += _locationsVisited.top()->DisplayLocationInfo() + "\n";
		_locationsVisited.pop();
	}

	result += "\nReturning to Pallet Town....\n";

	CurrentLocation = HomePointer;

	return result;
}
