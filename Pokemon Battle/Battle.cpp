#pragma once
#include "Battle.h"
#include "Trainer.h"
#include "WildPkmn.h"

void WildEncounter(Trainer Player)
{
	string playerMonster;
	char input;
	bool didCatch;
	int pokeballs = 5;

	WildPkmn monster = WildPkmn(randomNameGenerator());
	didCatch = captureAttempt(monster.GetCombatPower());


	cout << "!" << endl;
	cout << "A wild " << monster.GetName() << " appeared!" << endl;
	cout << "Battle it? <Y/N>" << endl;
	cin >> input;
	input = tolower(input);

	if (input == 'y')
	{
		playerMonster = Player.Pokemon.GetName();
		cout << endl << "Go! " << playerMonster << "!\n\n";
		cout << "Opponent:\n" << monster.GetName() << endl;
		cout << "Player:\n" << playerMonster << "\n\n";
		cout << playerMonster << " attacked " << monster.GetName() << "! It is critically weakened!\n\n";
		cout << "You have " << pokeballs << " Pokeballs. Do you want to attempt to capture " << monster.GetName() << "? <Y/N>" << endl;
		cin >> input;
		input = tolower(input);

		while (pokeballs > 0 && input == 'y')
		{
			system("cls");
			if (input == 'y')
			{
				pokeballs--;
				cout << endl << "Threw a pokeball at " << monster.GetName() << "! It shook once... twice..." << endl;
				if (didCatch)
				{
					cout << "\nYES! " << monster.GetName() << " was caught!" << endl;
					cout << "Added " << monster.GetName() << " to the Pokedex!" << endl;
					cout << monster.GetName() << " was sent to Bill's PC!\n\n";

					return;
				}
				else
				{
					cout << "Darn! " << monster.GetName() << " broke free! It was so close!" << endl;
					cout << "You have " << pokeballs << " Pokeballs left." << endl;
					if (pokeballs > 0)
					{
						cout << endl << "Throw another Pokeball? <Y/N>" << endl;
						cin >> input;
						input = tolower(input);
						didCatch = captureAttempt(monster.GetCombatPower());
					}
				}
			}
			else
			{
				cout << endl << "Got away safely...\n\n";
				return;
			}
		}
		cout << endl << "You ran out of Pokeballs! Got away safely..." << endl;

	}
}

bool captureAttempt(int combatPower)
{
	int captureChance;

	if (combatPower < 10)
	{
		captureChance = rand() % 2;
	}
	else if (combatPower >= 10 && combatPower <= 20)
	{
		captureChance = rand() % 4;
	}
	else if (combatPower > 20)
	{
		captureChance = rand() % 8;
	}

	if (captureChance == 0)
	{
		return true;
	}

	return false;
}

string randomNameGenerator()
{
	srand(time(NULL));
	string monsterName;


	vector <string> names =
	{
		"Charmander", "Bulbasaur", "Squirtle", "Pidgey", "Pikachu",
		"Sandshrew", "Zubat", "Mankey", "Abra", "Magikarp",
		"Eevee", "Rattata", "Vulpix", "Scyther", "Jigglypuff",
		"Geodude", "Onix", "Staryu", "Snorlax", "Mewtwo",
		"Oddish", "Caterpie", "Spearow", "Charizard", "Zapdos",
		"Missingno."
	};

	monsterName = names[rand() % 26];

	return monsterName;
}
