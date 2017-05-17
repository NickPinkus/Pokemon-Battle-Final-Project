#pragma once
#include <stack>
#include <queue>
#include "Location.h"
#include <unordered_map>
using namespace std;

class Map
{
private:
	stack<Location *> _locationsVisited;
	queue<Location *> _HowDidIGetHere;
	
	unordered_map<string, Location *> _mapLookup;
	Location * HomePointer = nullptr;
	
public:
	Map(string startLocationName);
	~Map();

	Location * CurrentLocation = nullptr;
	string GetPathBackToHome();
	void Move(Location *newLocation);
	Location * LookupLocationOnMap(int x, int y);
	void AddToMap(string, Location *);
	string HowDidIGetHere();
};

