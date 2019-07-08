/*
* Shifra Schectman
* Lab 3
* Game Class Header File
* April 22, 2018
*/
#include "Game.hpp"

Game::Game()
{
	int sidesP1 = M.numberOfSidesP1();
	if (M.typeOfDieP1() == 1)
	{
		P1 = new Die(sidesP1);
	}
	else
	{
		P1 = new LoadedDie(sidesP1);
	}

	int sidesP2 = M.numberOfSidesP2();
	if (M.typeOfDieP2() == 1)
	{
		P2 = new Die(sidesP2);
	}

	else
	{
		P2 = new LoadedDie(sidesP2);
	}
}

/*
* This function initializes the loop 
* for each round, spins the die and 
* displays the results
*/
void Game::playGame()
{
	int numberOfRounds = M.numberOfRounds();
	int sidesP1=P1->getNumberOfSides();
	int sidesP2 = P2->getNumberOfSides();
	for (int i = 0; i <  numberOfRounds; i++)
	{
		int P1spin = P1->spinDie(sidesP1);
		int P2spin = P2->spinDie(sidesP2);
		if (P1spin == P2spin);
		else if (P1spin > P2spin)
		{
			scoreP1++;
		}
		else if (P1spin < P2spin)
		{
			scoreP2++;
		}
		std::cout << "Player One spun a " << P1spin << std::endl;
		std::cout << "with " << P1->getNumberOfSides() << " faces" << std::endl;
		std::cout << "Player Two spun a " << P2spin << std::endl;
		std::cout << "with " << P2->getNumberOfSides() << " faces" << std::endl;
	}

}

/*
* This function asks the user to
* display the score after the game
*/
void Game::displayScore()
{
	std::cout << "The final score for Player One is " << scoreP1 << std::endl;
	std::cout << "The final score for Player Two is " << scoreP2 << std::endl;

	if (scoreP1 > scoreP2)
	{
		std::cout << "Player One Wins!";
	}
	else if (scoreP1 < scoreP2)
	{
		std::cout << "Player Two Wins!";
	}
	else
	{
		std::cout << "Tie Game";
	}
}

Game::~Game()
{
	delete P1;
	delete P2;
}


