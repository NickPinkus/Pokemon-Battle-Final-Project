#pragma once
#include <iostream>
#include "mapmain.h"
#include <ctime>
using namespace std;

int MapMovement()
{
	auto map = Map("Pallet Town");
	int routeNumber = 1;
	int choice = -1;
	while (choice != 0) 
	{
		system("cls");
		cout << map.CurrentLocation->DisplayLocationInfo()	<< endl;
		cout << "1) Go North"								<< endl;
		cout << "2) Go East"								<< endl;
		cout << "3) Go South"								<< endl;
		cout << "4) Go West"								<< endl;
		cout << "5) Search Tall Grass for Pokemon"			<< endl;
		cout << "6) Return to Pallet Town"					<< endl;
		cin >> choice;

		switch (choice) 
		{
		case 1: GoNorth(map, routeNumber); break;
		case 2: GoEast(map, routeNumber); break;
		case 3: GoSouth(map, routeNumber); break;
		case 4: GoWest(map, routeNumber); break;
		case 5: system("cls"); cout << "Implement this" << endl; break;
		case 6: system("cls"); cout << map.GetPathBackToHome() << endl; break;
		default: cout << "Enter a valid option" << endl; break;
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
			cout << "Now entering "<< existing->DisplayLocationInfo() << endl;
			map.CurrentLocation->North = existing;
			existing->South = map.CurrentLocation;
			map.Move(existing);
			
		}
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo() << endl;
		newLocation->South = map.CurrentLocation;
		map.Move(newLocation);
	}
	
	return;
}

void GoEast(Map &map, int &routeNumber)
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
			cout << "You've discovered Route " << routeNumber << endl;
			newLocation = new Location("Route " + to_string(routeNumber), newX, newY);
			routeNumber++;
			map.AddToMap("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "Now entering "<< existing->DisplayLocationInfo() << endl;
			map.CurrentLocation->East = existing;
			existing->West = map.CurrentLocation;
			map.Move(existing);


		}
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo() << endl;
		newLocation->West = map.CurrentLocation;
		map.Move(newLocation);
	}

	return;
}

void GoSouth(Map &map, int &routeNumber)
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
			cout << "You've discovered Route " << routeNumber << endl;
			newLocation = new Location("Route " + to_string(routeNumber), newX, newY);
			routeNumber++;
			map.AddToMap("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{

			cout << "Now entering "<< existing->DisplayLocationInfo() << endl;
			map.CurrentLocation->South = existing;
			existing->North = map.CurrentLocation;
			map.Move(existing);

		}
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo() << endl;
		newLocation->North = map.CurrentLocation;
		map.Move(newLocation);

	}

	return;
}

void GoWest(Map &map, int &routeNumber)
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
			cout << "You've discovered Route " << routeNumber << endl;
			newLocation = new Location("Route " + to_string(routeNumber), newX, newY);
			routeNumber++;
			map.AddToMap("(" + to_string(newX) + "," + to_string(newY) + ")", newLocation);
			map.Move(newLocation);
		}
		else
		{
			cout << "Now entering "<< existing->DisplayLocationInfo() << endl;
			map.CurrentLocation->West = existing;
			existing->East = map.CurrentLocation;
			map.Move(existing);

		}
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo() << endl;
		newLocation->East = map.CurrentLocation;
		map.Move(newLocation);
	}

	return;
}

void SearchTallGrass()
{
	cout << "You approach the nearest patch of tall grass..." << endl;

	system("pause");
	system("cls");

	srand(time(NULL));

	/*bool pokemonAppears = rand() % 2;


	if (pokemonAppears = true)
	{
		cout << "A wild " << pokemonName << " appeared!";
	}
	else
	{
		cout << "But nothing happened..." << endl;
	}*/
}