/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
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
	while (P1->getStrengthPoints() >0 && P2->getStrengthPoints() > 0)
	{
		std::cout << std::endl;
		std::cout << "Player One: " << P1->getType() << " ATTACKS  Player Two: " << P2->getType() << std::endl;
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
			std::cout << "Player Two: " << P2->getType() << " ATTACKS  Player One: " << P1->getType() << std::endl;
			std::cout << std::endl;
			std::cout << "Defender has " << P1->getStrengthPoints() << " strength points and " << P1->getArmor() << " armor." << std::endl;
			//call p2 attack 
			int P2attack = P2->attack();
			//call p1 defense
			P1->defense(P2attack);
		}
		else
		{
			std::cout << std::endl;
			std::cout << "PLAYER TWO LOSES!" << std::endl;
		}
	} 
	std::cout << std::endl;
	if (P1->getStrengthPoints() <= 0)
	{
		std::cout << std::endl;
		std::cout << "PLAYER ONE LOSES!" << std::endl;
	}
	//delete memory
	delete P1;
	delete P2;
	
}
