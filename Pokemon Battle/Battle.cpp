#pragma once
#include "Battle.h"
#include "Trainer.h"

void WildEncounter(Trainer Player)
{
	WildPokemon monster;
	string playerMonster;
	char input;
	bool didCatch;
	int pokeballs = 5;

	monster = setMonster();
	didCatch = captureAttempt(monster.combatPower);


	cout << "!" << endl;
	cout << "A wild " << monster.name << " appeared!" << endl;
	cout << "Battle it? <Y/N>" << endl;
	cin >> input;
	input = tolower(input);

	if (input == 'y')
	{
		playerMonster = Player.Pokemon.GetName();
		cout << endl << "Go! " << playerMonster << "!\n\n";
		cout << "Opponent:" << endl;
		printMonster(monster);
		cout << "Player:\n" << playerMonster << "\n\n";
		cout << playerMonster << " attacked " << monster.name << "! It is critically weakened!\n\n";
		cout << "You have " << pokeballs << " Pokeballs. Do you want to attempt to capture " << monster.name << "? <Y/N>" << endl;
		cin >> input;
		input = tolower(input);

		while (pokeballs > 0 && input == 'y')
		{
			system("cls");
			if (input == 'y')
			{
				pokeballs--;
				cout << endl << "Threw a pokeball at " << monster.name << "! It shook once... twice..." << endl;
				if (didCatch)
				{
					cout << "\nYES! " << monster.name << " was caught!" << endl;
					cout << "Added " << monster.name << " to the Pokedex!" << endl;
					cout << monster.name << " was sent to Bill's PC!\n\n";

					return;
				}
				else
				{
					cout << "Darn! " << monster.name << " broke free! It was so close!" << endl;
					cout << "You have " << pokeballs << " Pokeballs left." << endl;
					if (pokeballs > 0)
					{
						cout << endl << "Throw another Pokeball? <Y/N>" << endl;
						cin >> input;
						input = tolower(input);
						didCatch = captureAttempt(monster.combatPower);
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

WildPokemon setMonster()
{
	WildPokemon x;
	x.name = randomNameGenerator();
	x.combatPower = rand() % 25;

	return x;
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

void printMonster(WildPokemon monster)
{
	cout << monster.name << "\n\n";
}