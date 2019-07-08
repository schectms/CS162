/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
* Game Source File
*/

#include "Game.hpp"

/*
choose character function allocates memory for the character chosen

*/
Character *Game::chooseCharacter()
{
	//switch statement based on choose char menu function 
	switch (M.chooseCharacter())
	{
	case 1:
		Vampire * V;
		V = new Vampire();
		return V;
		break;
	case 2:
		Barbarian * B;
		B = new Barbarian();
		return B;
		break;
	case 3:
		BlueMen * BM;
		BM = new BlueMen();
		return BM;
		break;
	case 4:
		Medusa * M;
		M = new Medusa();
		return M;
		break;
	case 5:
		HarryPotter * HP;
		HP = new HarryPotter();
		return HP;
		break;
	}
}

/*
round function that takes p1 and p2 as parameters and simulates one round in the battle between these charcters
*/
void Game::round(Character *P1, Character *P2)
{
	//while both characters are alive
	while (P1->getStrengthPoints() > 0 && P2->getStrengthPoints() > 0)
	{
		std::cout << std::endl;
		std::cout << "Player One: " << P1->getType() <<" " << P1->getName() << " ATTACKS  Player Two: " << P2->getType() << " "<< P2->getName() << std::endl;
		std::cout << std::endl;
		std::cout << "Defender has " << P2->getStrengthPoints() << " strength points and " << P2->getArmor() << " armor." << std::endl;
		//call attack function for p1
		int P1attack = P1->attack();
		//call p2 defense
		P2->defense(P1attack);
		std::cout << std::endl;

		//while p2 is alive
		if (P2->getStrengthPoints() > 0)
		{
			std::cout << "Player Two: " <<P2->getType() << " "<< P2->getName() << " ATTACKS  Player One: " <<P1->getType() << " " << P1->getName() << std::endl;
			std::cout << std::endl;
			std::cout << "Defender has " << P1->getStrengthPoints() << " strength points and " << P1->getArmor() << " armor." << std::endl;
			//call p2 attack 
			int P2attack = P2->attack();
			//call p1 defense
			P1->defense(P2attack);
		}
	}
	std::cout << std::endl;
	//when Player One loses
	if (P1->getStrengthPoints() <= 0)
	{
		std::cout << std::endl;
		std::cout << P2->getName() << " WINS!" << std::endl;
		//remove head of Team2
		Team2.removeFront();
		//restore damage
		P2->setStrengthPoints(P2->getStrengthPoints()+P2->restoreDamage());
		//add back to the end
		Team2.addBack(P2);
		//remove front of team 1
		Team1.removeFront();
		//add to loser queue
		Losers.addBack(P1);
		//add to p2 score
		P2Score += 2;

	}
	//when player Two Loses
	else if (P2->getStrengthPoints() <= 0)
	{
		std::cout << std::endl;
		std::cout << P1->getName() << " WINS!" << std::endl;
		//remove head of team 1
		Team1.removeFront();
		//restore damage
		P1->setStrengthPoints(P1->getStrengthPoints() + P1->restoreDamage());
		//add back to the end
		Team1.addBack(P1);
		//remove front of team 2
		Team2.removeFront();
		//add to loser queue
		Losers.addBack(P2);
		//calculate score
		P1Score += 2;
	}
	
}

/*
tournamnet function calls round function while both teaams have players
*/
void Game::tournament()
{
	//while there are heads on both teams
	while (Team2.isEmpty() == false && Team1.isEmpty() == false)
	{
		//if(Team2.isEmpty()==false)
		//run round with head of each team
		round(Team1.getFront(), Team2.getFront());
	}
}

/*
runGame function goes through game
*/
void Game::runGame()
{
		int numOfPlayers = M.numberOfPlayers();
		//ask  player to choose characters
		std::cout << "Player " << 1 << " Choose Your Characters" << std::endl;
		for (int i = 0; i < numOfPlayers; i++)
		{
			//initialize characters 
			P1 = chooseCharacter();
			//input and set names
			P1->setName(M.enterName());
			//add to queue
			Team1.addBack(P1);
		}
		//ask player 2 to choose characters
		std::cout << "Player " << 2 << " Choose Your Characters" << std::endl;
		for (int i = 0; i < numOfPlayers; i++)
		{
			//initialize char
			P2 = chooseCharacter();
			//input and set name
			P2->setName(M.enterName());
			//add to queue
			Team2.addBack(P2);
		}

		//calls tournament function
		tournament();
		//displays score
		displayScore();
		//ask user if he wants to display queue and displays it if yes
		if(M.displayLosers()==1)
		{
			Losers.printQueue();
		}
		std::cout << std::endl;

}
/*

displayScore function displays the score of the game*/
void Game::displayScore()
{
	//display winner or tie
	if (P1Score>P2Score)
	{
		std::cout << "TEAM 1 WINS!" << std::endl;
	}
	else if (P2Score>P1Score)
	{
		std::cout << "TEAM 2 WINS!" << std::endl;
	}
	else
	{
		std::cout << "TIE GAME" << std::endl;
	}
	//display score
	std::cout << "Team 1 has " << P1Score << " points, and Team 2 has " << P2Score << " points." << std::endl;
}
