#include <iostream>
#include <memory>
#include "Trainer.h"
#include "mapmain.h"

string nameValidate();

void NewGame();
void Battle(Trainer Player, Trainer Opponent);
bool BattleRecursionPrompt(shared_ptr<Trainer> playerPTR, shared_ptr<Trainer> opponentPTR);
bool checkWinCondition(shared_ptr<Trainer> playerPTR, shared_ptr<Trainer> opponentPTR);

int main()
{
	cout << "Pokemon: CMD Version\n\n" << "Please choose an option:\n\n" << "N- New Game\n" << "E- Exit";

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

	Trainer Player = Trainer(NameSet);

	cout << "\nOak: " << Player.GetName() << ", huh? That's a cool name!\n\n";
	system("pause");
	system("cls");
	cout << "Oak: Ah! I see you came here with my grandson! What was his name again?\n\n"
		 << "Name: ";

	NameSet = nameValidate();
	Trainer Opponent = Trainer(NameSet);

	cout << "Oak: Oh, that's right! His name is " << Opponent.GetName() << "!\n\n";

	system("pause");
	system("cls");

	cout << "Oak: " << Player.GetName() << "! I have three Pokemon here!" << endl
		 << "You can choose one as your companion!\n\n";
	getchar();
	cout << Opponent.GetName() << ": Gramps, what about me?" << endl;
	getchar();
	cout << "\nOak: " << Opponent.GetName() << "! I forgot you were coming! You can pick one too!\n\n";

	system("pause");
	system("cls");

	enum pokemon { Bulbasaur, Charmander, Squirtle, Pikachu, Eevee };
	cout << Player.GetName() << ", choose a Pokemon:" << endl
		 << "(1) Bulbasaur - Grass Type"              << endl
		 << "(2) Charmander - Fire Type"              << endl
		 << "(3) Squirtle - Water Type"               << endl;
	cin >> playerchoice;
	switch (playerchoice)
	{
	case 1:
		Player.Pokemon.SetIDNum(Bulbasaur);
		Opponent.Pokemon.SetIDNum(Charmander);
		break;
	case 2:
		Player.Pokemon.SetIDNum(Charmander);
		Opponent.Pokemon.SetIDNum(Squirtle);
		break;
	case 3:
		Player.Pokemon.SetIDNum(Squirtle);
		Opponent.Pokemon.SetIDNum(Bulbasaur);
		break;
	default:
		Player.Pokemon.SetIDNum(Pikachu);
		Opponent.Pokemon.SetIDNum(Eevee);
	}

	Player.Pokemon.SetInfo();
	Opponent.Pokemon.SetInfo();


	cout << "\n\n" << Player.GetName() << " chose " << Player.Pokemon.GetName() << "!" << endl;
	cout << "\n\n" << Opponent.GetName() << ": Then I'll choose this one!\n\n";
	cout << Opponent.GetName() << " chose " << Opponent.Pokemon.GetName() << "!\n\n";
	
	system("pause");
	system("cls");

	cout << Opponent.GetName() << ": Hey, " << Player.GetName() << "! Let's have a Pokemon battle!" << endl;

	getchar();

	Battle(Player, Opponent);

	system("cls");

	
}

void Battle(Trainer Player, Trainer Opponent)
{
	int playerchoice;
	auto playerPTR = make_shared<Trainer>(Player);
	auto opponentPTR = make_shared<Trainer>(Opponent);
	bool check = false;

	srand(time(NULL));

	cin.ignore();

	cout << "Trainer " << opponentPTR->GetName() << " challenges Trainer " << Player.GetName() << " to a battle!\n\n";
	getchar();
	cout << "Trainer " << opponentPTR->GetName() << " sends out " << Opponent.Pokemon.GetName() << "!" << endl;

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
			case 1:
				if (playerPTR->Inventory[0].GetItemCount() > 0 && playerPTR->Pokemon.Health + 5 <= playerPTR->Pokemon.GetMaxHealth())
				{
					playerPTR->Inventory[0].UseItem();
					playerPTR->Pokemon.Health += 5;
					cout << playerPTR->GetName() << " used a " << playerPTR->Inventory[0].GetItemName() << endl;
				}
				else if (playerPTR->Inventory[0].GetItemCount() > 0 && playerPTR->Pokemon.Health + 5 >= playerPTR->Pokemon.GetMaxHealth())
				{
					playerPTR->Inventory[0].UseItem();
					playerPTR->Pokemon.Health = playerPTR->Pokemon.GetMaxHealth();
					cout << playerPTR->GetName() << " used a " << playerPTR->Inventory[0].GetItemName() << endl;
				}
				else
				{
					cout << "You do not have any " << playerPTR->Inventory[0].GetItemName() << "s left!" << endl;
				}

				break;
			case 2:
				cout << "Pokeball! Go!" << endl;
				cout << playerPTR->GetName() << "! You can't steal another trainer's Pokemon!" << endl;
				playerPTR->Inventory[1].UseItem();
				break;
			}
			break;
		}
		//Check for player win condition
		check = checkWinCondition(playerPTR, opponentPTR);
		if (check == true)
		{
			return;
		}

		system("pause");
		system("cls");

		//Opponent's Turn
		playerchoice = rand() % 2 + 1;
		switch (playerchoice)
		{
		case 1:
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

		case 2:
			if (opponentPTR->Inventory[0].GetItemCount() > 0 && opponentPTR->Pokemon.Health + 5 <= opponentPTR->Pokemon.GetMaxHealth())
			{
				opponentPTR->Pokemon.Health += 5;
				opponentPTR->Inventory[0].UseItem();
				cout << opponentPTR->GetName() << " used a " << opponentPTR->Inventory[0].GetItemName() << endl;
			}
			else if (opponentPTR->Inventory[0].GetItemCount() > 0 && opponentPTR->Pokemon.Health + 5 >= opponentPTR->Pokemon.GetMaxHealth())
			{
				opponentPTR->Pokemon.Health = opponentPTR->Pokemon.GetMaxHealth();
				opponentPTR->Inventory[0].UseItem();
				cout << opponentPTR->GetName() << " used a " << opponentPTR->Inventory[0].GetItemName() << endl;
			}
			break;
		}

		//Check for Opponent Win Condition
		check = checkWinCondition(playerPTR, opponentPTR);
		if (check == true)
		{
			return;
		}

		system("pause");
		system("cls");
	}
}

bool BattleRecursionPrompt(shared_ptr<Trainer> playerPTR, shared_ptr<Trainer> opponentPTR)
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

bool checkWinCondition(shared_ptr<Trainer> playerPTR, shared_ptr<Trainer> opponentPTR)
{

	if (opponentPTR->Pokemon.Health <= 0)
	{
		cout << opponentPTR->Pokemon.GetName() << " has fainted." << endl
			<< "Trainer " << playerPTR->GetName() << " defeated Trainer " << opponentPTR->GetName() << "!\n\n";

		cout << opponentPTR->GetName() << ": Whatever... My Pokemon is weak. I'm going to force it to get stronger!\n\n";

		system("pause");

		bool battleRecursion = BattleRecursionPrompt(playerPTR, opponentPTR);
		if (battleRecursion == true)
		{
			Battle(*playerPTR, *opponentPTR);
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
			Battle(*playerPTR, *opponentPTR);
		}
		return true;
	}
	return false;
}