#pragma once
#include <string>
using namespace std;

class Location
{
private:
	string _name;
	int _xCoord = 0;
	int _yCoord = 0;
public:
	Location(string name, int xCoord, int yCoord);
	~Location();
	string DisplayLocationInfo();

	Location *North = nullptr;
	Location *South = nullptr;
	Location *East = nullptr;
	Location *West = nullptr;

	int getXCoord() { return _xCoord; }
	int getYCoord() { return _yCoord; }
	string getNewCoordinates(int, int);
};

