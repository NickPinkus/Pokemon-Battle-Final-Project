#include <iostream>
#include <memory>
#include "Trainer.h"
#include "mapmain.h"
#include "Battle.h"

string nameValidate();

void NewGame();
void Battle(Trainer * Player, Trainer * Opponent);
bool BattleRecursionPrompt(Trainer * playerPTR, Trainer * opponentPTR);
bool CheckWinCondition(Trainer * playerPTR, Trainer * opponentPTR);

int main()
{
	cout << "Pokemon: CMD Version\n\n" << "Please choose an option:\n\n" << "N- New Game\n" << "E- Exit\n";

	char playerChoice = 'z';
	cin >> playerChoice;
	playerChoice = toupper(playerChoice);

	switch (playerChoice)
	{
	case 'N': system("cls"); NewGame(); break;
	case 'E': return 0;
	}

	system("pause");



	return 0;
}

string nameValidate()
{
	string setname;
	getline(cin, setname);
	while (setname.empty())
	{
		cout << "Oak: Hey, look. I'm old. You're going to need to speak up." << endl;
		getline(cin, setname);
	}

	return setname;
}

void NewGame()
{
	int playerchoice = 0;
	string NameSet = "DEFAULT";

	cout << "Oak: Hello, welcome to the world of Pokemon!"        << endl
		 << "My name is Oak! People call me a Pokemon Professor!" << endl
		 << "What about you? What is your name?\n\n"
		 << "Name: ";

	cin.ignore();
	NameSet = nameValidate();

	Trainer * Player = new Trainer(NameSet);

	cout << "\nOak: " << Player->GetName() << ", huh? That's a cool name!\n\n";
	system("pause");
	system("cls");
	cout << "Oak: Ah! I see you came here with my grandson! What was his name again?\n\n"
		 << "Name: ";

	NameSet = nameValidate();
	Trainer * Opponent = new Trainer(NameSet);

	cout << "Oak: Oh, that's right! His name is " << Opponent->GetName() << "!\n\n";

	system("pause");
	system("cls");

	cout << "Oak: " << Player->GetName() << "! I have three Pokemon here!" << endl
		 << "You can choose one as your companion!\n\n";
	getchar();
	cout << Opponent->GetName() << ": Gramps, what about me?" << endl;
	getchar();
	cout << "\nOak: " << Opponent->GetName() << "! I forgot you were coming! You can pick one too!\n\n";

	system("pause");
	system("cls");

	enum pokemon { Bulbasaur, Charmander, Squirtle, Pikachu, Eevee, Pidgey, Meowth};
	cout << Player->GetName() << ", choose a Pokemon:" << endl
		 << "(1) Bulbasaur - Grass Type"              << endl
		 << "(2) Charmander - Fire Type"              << endl
		 << "(3) Squirtle - Water Type"               << endl
		 << "(4) Pikachu - Electric Type"			  << endl
		 << "(5) Meowth - Normal Type"				  << endl;

	cin >> playerchoice;
	while (playerchoice < 1 || playerchoice > 5)
	{
		cout << "\nOak: You can't choose a Pokemon that I don't have!\n";
		cin >> playerchoice;
	}

	switch (playerchoice)
	{
	case 1:
		Player->Pokemon.SetIDNum(Bulbasaur);
		Opponent->Pokemon.SetIDNum(Charmander);
		break;
	case 2:
		Player->Pokemon.SetIDNum(Charmander);
		Opponent->Pokemon.SetIDNum(Squirtle);
		break;
	case 3:
		Player->Pokemon.SetIDNum(Squirtle);
		Opponent->Pokemon.SetIDNum(Bulbasaur);
		break;
	case 4:
		Player->Pokemon.SetIDNum(Pikachu);
		Opponent->Pokemon.SetIDNum(Eevee);
		break;
	case 5:
		Player->Pokemon.SetIDNum(Meowth);
		Opponent->Pokemon.SetIDNum(Pidgey);
		break;
	}

	Player->Pokemon.SetInfo();
	Opponent->Pokemon.SetInfo();


	cout << "\n\n" << Player->GetName() << " chose " << Player->Pokemon.GetName() << "!" << endl;
	cout << "\n\n" << Opponent->GetName() << ": Then I'll choose this one!\n\n";
	cout << Opponent->GetName() << " chose " << Opponent->Pokemon.GetName() << "!\n\n";
	
	system("pause");
	system("cls");

	cout << Opponent->GetName() << ": Hey, " << Player->GetName() << "! Let's have a Pokemon battle!" << endl;

	getchar();

	Battle(Player, Opponent);

	system("cls");
	cout << "Oak: Well done, you two! Now get out there and catch some more Pokemon!" << endl;
	system("pause");
	system("cls");
	MapMovement(*Player);

	
}

void Battle(Trainer * playerPTR, Trainer * opponentPTR)
{
	int playerchoice;
//	auto playerPTR = make_shared<Trainer>(Player);
//	auto opponentPTR = make_shared<Trainer>(Opponent);
	bool check = false;

	srand(time(NULL));

	cin.ignore();

	cout << "Trainer " << opponentPTR->GetName() << " challenges Trainer " << playerPTR->GetName() << " to a battle!\n\n";
	getchar();
	cout << "Trainer " << opponentPTR->GetName() << " sends out " << opponentPTR->Pokemon.GetName() << "!" << endl;

	getchar();

	cout << "Go! " << playerPTR->Pokemon.GetName() << "!\n\n";

	system("pause");
	system("cls");

	while (playerPTR->Pokemon.Health > 0 && playerPTR->Pokemon.Health > 0)
	{
		cout << opponentPTR->Pokemon.GetName() << endl
			 << "Health: " << opponentPTR->Pokemon.Health
			 << "/" << opponentPTR->Pokemon.GetMaxHealth() << "\n\n";

		cout << playerPTR->Pokemon.GetName() << endl
			 << "Health: " << playerPTR->Pokemon.Health
			 << "/" << playerPTR->Pokemon.GetMaxHealth() << "\n\n";

	//Start Player's Turn

		cout << "(1) Attack / (2) Items" << endl
			<< "Your Choice: ";
		cin >> playerchoice;

		system("cls");

		switch (playerchoice)
		{
		case 1:
			cout << playerPTR->Pokemon.GetName() << "'s attacks:" << endl
				 << "(1)" << playerPTR->Pokemon.Attack1.GetAttackName()     << endl
				 << "(2)" << playerPTR->Pokemon.Attack2.GetAttackName()     << endl
				 << "Your Choice: \n";
			cin  >> playerchoice;

			if (playerchoice == 1)
			{
				cout << playerPTR->Pokemon.GetName() << " used " << playerPTR->Pokemon.Attack1.GetAttackName() << "!";
				opponentPTR->Pokemon.Health -= playerPTR->Pokemon.Attack1.calculateAttackDamage();
				if (playerPTR->Pokemon.Attack1.GetAttackName() == "Fury Swipes")
				{
					playerPTR->Pokemon.Attack1.RestoreFurySwipes();
				}
			}
			else
			{
				cout << playerPTR->Pokemon.GetName() << " used " << playerPTR->Pokemon.Attack2.GetAttackName() << "!";
				opponentPTR->Pokemon.Health -= playerPTR->Pokemon.Attack2.calculateAttackDamage();
			}

			break;

		case 2:
			int itemNumber = 1;
			for (int i = 0; i < sizeof(playerPTR->Inventory)/sizeof(*playerPTR->Inventory); i++)
			{
				if (playerPTR->Inventory[i].GetItemCount() >= 0)
				{
					cout << "(" << itemNumber << ") " << playerPTR->Inventory[i].GetItemName()
						 << " x" << playerPTR->Inventory[i].GetItemCount() << endl;
					itemNumber++;
				}
			}
			cin >> playerchoice;
			switch (playerchoice)
			{
			case 2:
				cout << "Pokeball! Go!" << endl;
				cout << "Oak: " << playerPTR->GetName() << "! You can't steal another trainer's Pokemon!" << endl;
				playerPTR->Inventory[1].UseItem();
				break;
			case 1:
				if (playerPTR->Inventory[0].GetItemCount() > 0 && playerPTR->Pokemon.Health + 5 <= playerPTR->Pokemon.GetMaxHealth())
				{
					playerPTR->Inventory[0].UseItem();
					playerPTR->Pokemon.Health += 5;
					cout << playerPTR->GetName() << " used a " << playerPTR->Inventory[0].GetItemName() << endl;
					break;
				}
				else if (playerPTR->Inventory[0].GetItemCount() > 0 && playerPTR->Pokemon.Health + 5 >= playerPTR->Pokemon.GetMaxHealth())
				{
					playerPTR->Inventory[0].UseItem();
					playerPTR->Pokemon.Health = playerPTR->Pokemon.GetMaxHealth();
					cout << playerPTR->GetName() << " used a " << playerPTR->Inventory[0].GetItemName() << endl;
					break;
				}
				else
				{
					cout << "You do not have any " << playerPTR->Inventory[0].GetItemName() << "s left!" << endl;
					break;
				}


			}
			break;
		}
		//Check for player win condition
		check = CheckWinCondition(playerPTR, opponentPTR);
		if (check == true)
		{
			return;
		}

		//Opponent's Turn
		playerchoice = rand() % 5;
		switch (playerchoice)
		{
		case 0:
			if (opponentPTR->Inventory[0].GetItemCount() > 0 && opponentPTR->Pokemon.Health + 5 <= opponentPTR->Pokemon.GetMaxHealth())
			{
				opponentPTR->Pokemon.Health += 5;
				opponentPTR->Inventory[0].UseItem();
				cout << opponentPTR->GetName() << " used a " << opponentPTR->Inventory[0].GetItemName() << endl;
				break;
			}
			else if (opponentPTR->Inventory[0].GetItemCount() > 0 && opponentPTR->Pokemon.Health + 5 >= opponentPTR->Pokemon.GetMaxHealth())
			{
				opponentPTR->Pokemon.Health = opponentPTR->Pokemon.GetMaxHealth();
				opponentPTR->Inventory[0].UseItem();
				cout << opponentPTR->GetName() << " used a " << opponentPTR->Inventory[0].GetItemName() << endl;
				break;
			}
			else if (opponentPTR->Inventory[0].GetItemCount() <= 0)
			{
				playerchoice = 1;
			}
		default:
			playerchoice = rand() % 2 + 1;

			if (playerchoice == 1)
			{
				cout << opponentPTR->Pokemon.GetName() << " used " << opponentPTR->Pokemon.Attack1.GetAttackName() << "!";
				playerPTR->Pokemon.Health -= opponentPTR->Pokemon.Attack1.calculateAttackDamage();
			}
			else
			{
				cout << opponentPTR->Pokemon.GetName() << " used " << opponentPTR->Pokemon.Attack2.GetAttackName() << "!";
				playerPTR->Pokemon.Health -= opponentPTR->Pokemon.Attack2.calculateAttackDamage();
			}

			break;
		}

		//Check for Opponent Win Condition
		check = CheckWinCondition(playerPTR, opponentPTR);
		if (check == true)
		{
			return;
		}
	}
}

bool BattleRecursionPrompt(Trainer * playerPTR, Trainer * opponentPTR)
{
	system("cls");

	char playerchoice = 'z';

	cout << "Battle Trainer " << opponentPTR->GetName() << " again? <Y/N>";

	cin.ignore();
	cin >> playerchoice;
	playerchoice = toupper(playerchoice);

	while (playerchoice != 'Y' && playerchoice != 'N')
	{
		cout << "Choice must be 'Y' or 'N'" << endl;
		cin.ignore();
		cin >> playerchoice;
		playerchoice = toupper(playerchoice);
	}
	if (playerchoice == 'Y')
	{
		playerPTR->Pokemon.Health = playerPTR->Pokemon.GetMaxHealth();
		opponentPTR->Pokemon.Health = opponentPTR->Pokemon.GetMaxHealth();
		return true;
	}
	return false;
}

bool CheckWinCondition(Trainer * playerPTR, Trainer * opponentPTR)
{
	system("pause");
	system("cls");

	if (opponentPTR->Pokemon.Health <= 0)
	{
		cout << opponentPTR->Pokemon.GetName() << " has fainted." << endl
			 << "Trainer " << playerPTR->GetName() << " defeated Trainer " << opponentPTR->GetName() << "!\n\n";

		cout << opponentPTR->GetName() << ": Whatever... My Pokemon is weak. I'm going to force it to get stronger!\n\n";

		system("pause");

		bool battleRecursion = BattleRecursionPrompt(playerPTR, opponentPTR);
		if (battleRecursion == true)
		{
			Battle(playerPTR, opponentPTR);
		}
		return true;
	}
	else if (playerPTR->Pokemon.Health <= 0)
	{
		cout << endl << playerPTR->Pokemon.GetName() << " has fainted." << endl
			<< playerPTR->GetName() << " blacked out.\n\n";

		system("pause");

		bool battleRecursion = BattleRecursionPrompt(playerPTR, opponentPTR);
		if (battleRecursion == true)
		{
			Battle(playerPTR, opponentPTR);
		}
		return true;
	}
	return false;
}