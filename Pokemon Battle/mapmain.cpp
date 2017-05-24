#pragma once
#include <iostream>
#include "mapmain.h"
using namespace std;

int MapMovement()
{
	auto map = Map("Pallet Town");
	int routeNumber = 1;
	int choice = -1;
	while (choice != 0) 
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go West" << endl;
		cout << "6) Return to Pallet Town" << endl;
		cin >> choice;

		switch (choice) 
		{
		case 1: cout << "Current Location: " << map.CurrentLocation->DisplayLocationInfo(); break;
		case 2: GoNorth(map, routeNumber); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: system("cls"); cout << map.GetPathBackToHome() << endl; break;
		default: cout << "Enter a valid option"; break;
		}
		system("pause");
	}
	
	return 0;
}

void GoNorth(Map &map, int &routeNumber)
{
	auto newLocation = map.CurrentLocation->North;
	int currentX = map.CurrentLocation->getXCoord();
	int currentY = map.CurrentLocation->getYCoord();
	if (newLocation == nullptr) 
	{
		int newX = currentX;
		int newY = currentY + 1;
		auto existing = map.LookupLocationOnMap(newX, newY);
		system("cls");

		if (existing == nullptr)
		{
			cout << "You've discovered Route " << routeNumber << endl;
			newLocation = new Location("Route " + to_string(routeNumber), newX, newY);
			routeNumber++;
			map.AddToMap("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "Now entering Route " << routeNumber<< existing->DisplayLocationInfo();
			map.CurrentLocation->North = existing;
			existing->South = map.CurrentLocation;
			map.Move(existing);
			
		}
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo();
		newLocation->South = map.CurrentLocation;
		map.Move(newLocation);
	}
	
	return;
}

void GoEast(Map &map)
{
	auto newLocation = map.CurrentLocation->East;
	int currentX = map.CurrentLocation->getXCoord();
	int currentY = map.CurrentLocation->getYCoord();
	if (newLocation == nullptr)
	{
		int newX = currentX + 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		system("cls");

		if (existing == nullptr)
		{
			cout << "You haven't been here before! Enter a name for this place: ";
			string newName;
			cin.ignore();
			getline(cin, newName);
			newLocation = new Location(newName, newX, newY);
			cout << "This place is now called: " + newName << endl;
			map.AddToMap("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
			map.CurrentLocation->East = existing;
			existing->West = map.CurrentLocation;
			map.Move(existing);

		}
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo();
		newLocation->West = map.CurrentLocation;
		map.Move(newLocation);
	}

	return;
}

void GoSouth(Map &map)
{
	auto newLocation = map.CurrentLocation->South;
	int currentX = map.CurrentLocation->getXCoord();
	int currentY = map.CurrentLocation->getYCoord();
	if (newLocation == nullptr)
	{
		int newX = currentX;
		int newY = currentY - 1;
		auto existing = map.LookupLocationOnMap(newX, newY);
		system("cls");

		if (existing == nullptr)
		{
			cout << "You haven't been here before! Enter a name for this place: ";
			string newName;
			cin.ignore();
			getline(cin, newName);
			newLocation = new Location(newName, newX, newY);
			cout << "This place is now called: " + newName << endl;
			map.AddToMap("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
			map.CurrentLocation->South = existing;
			existing->North = map.CurrentLocation;
			map.Move(existing);

		}
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo();
		newLocation->North = map.CurrentLocation;
		map.Move(newLocation);

	}

	return;
}

void GoWest(Map &map)
{
	auto newLocation = map.CurrentLocation->West;
	int currentX = map.CurrentLocation->getXCoord();
	int currentY = map.CurrentLocation->getYCoord();
	if (newLocation == nullptr)
	{
		int newX = currentX - 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		system("cls");

		if (existing == nullptr)
		{
			cout << "You haven't been here before! Enter a name for this place: ";
			string newName;
			cin.ignore();
			getline(cin, newName);
			newLocation = new Location(newName, newX, newY);
			cout << "This place is now called: " + newName << endl;
			map.AddToMap("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "You've been here before. " << existing->DisplayLocationInfo();
			map.CurrentLocation->West = existing;
			existing->East = map.CurrentLocation;
			map.Move(existing);

		}
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo();
		newLocation->East = map.CurrentLocation;
		map.Move(newLocation);
	}

	return;
}