// This program simulates a secret agent who needs to hack into a corporate server to bring light upon a series of unfortunate events.
// The player must decipher the code and enter the right numbers into the terminal in order to breach the security protocol and access the data.
// This game was made by Kirk Paradis following the Unreal Engine C++ Developper: Learn C++ and Make Video Games course.

#include <iostream>
#include <ctime>

using namespace std;

void PrintGameLevel(int Difficulty)
{
	cout << "\nYou are on level " << Difficulty << endl;
}

void PrintTripleX()
{
	cout << "          #######  ######   ##  #####   #       #####      #   # " << endl;
	cout << "             #     #     #  ##  #    #  #       #           # #  " << endl;
	cout << "             #     ######   ##  #####   #       ####         #   " << endl;
	cout << "             #     #   #    ##  #       #       #           #  # " << endl;
	cout << "             #     #     #  ##  #       ######  #####      #    #" << endl;
}

void PrintMenu()
{
	cout << "\nP - Play" << endl;
	cout << "Q - Quit" << endl;
	cout << "C - Credits" << endl;
}


int ExitGame()
{
	cout << "\nExiting game..." << endl;
	return 0;
}

int GameCompleteMessage()
{
	cout << "\nYou have made it to the core of the servers and start looking at the data..." << endl;
	cout << "\nCould it be that... 2398rh239rh319r7g13897r1g39r8!@$#@$3hgr19378rhb319fdubn9317bd9p1....error@!#..." << endl;
	cout << "You've got123804124dsxwe To..1e2sxsdcs geT..g.32e23...OUT!!!23rfd..." << endl;

	return 0;
}


void PrintCredits()
{
	cout << "*********************************************************************************************************************" << endl;
	cout << "This game was made by Kirk Paradis following the Unreal Engine C++ Developper: Learn C++ and Make Video Games course." << endl;
	cout << "*********************************************************************************************************************" << endl;
}

bool PlayGame(int Difficulty) //Runs the game & applies the codes
{

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	int GuessA{}, GuessB{}, GuessC{};

	cout << "\nAgent, we're almost out of time." << "\n\nYou must decipher the access code to the server's core before it's too late!" << endl;
	cout << "\nThe code is made up of three numbers." << endl;
	cout << "The sum of the numbers is " << CodeSum << endl;
	cout << "The product of the numbers is " << CodeProduct << endl;

	cout << "\nEnter the first number..." << endl;
	cin >> GuessA;
	cout << "Now on to the second..." << endl;
	cin >> GuessB;
	cout << "and the last...think carefully..." << endl;
	cin >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		cout << "\n****************" << endl;
		cout << "\n***Well done!***" << endl;
		cout << "\n****************" << endl;
		return true;
	}
	else 
	{
		cout << "\n**********************************************************" << endl;
		cout << "\n***Careful, Agent! We almost got fried here. Try again.***" << endl;
		cout << "\n**********************************************************" << endl;
		return false;
	}

}

void GameRunOnStart()
{
	srand((unsigned int) time(NULL));
	int LevelDifficulty = 1;
	int const MaxLevel = 5;

	while (LevelDifficulty <= MaxLevel)
	{
		
		PrintGameLevel(LevelDifficulty);
		bool bLevelComplete = PlayGame(LevelDifficulty);
		cin.clear(); // clear the failbits
		cin.ignore(); // discards the buffer

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
}

void UserSelection()
{
	char selection{};

	cin >> selection;

	if (selection == 'P' || selection == 'p')
	{
		GameRunOnStart();
	}
	else if (selection == 'Q' || selection == 'q')
	{
		ExitGame();
	}
	else if (selection == 'C' || selection == 'c')
	{
		PrintCredits();
		PrintMenu();
		UserSelection();
	}
	else
	{
		cout << "Wrong selection, please try again." << endl;
	}

}

int main() 
{

	PrintTripleX();
	PrintMenu();
	UserSelection();

	GameCompleteMessage();

	return 0; // Exits the game

}