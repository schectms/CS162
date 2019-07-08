/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Source File
*/

#include "Menu.hpp"
#include "Character.hpp"
#include "Game.hpp"

int main()
{
	//seed random
	srand(time(NULL));
	//declare Game, Menu , Player 1 and Player 2
	Game G;
	Menu M;
	Character* P1;
	Character* P2;

	//loop while character chooses to continue
	do {
		//ask each player to choose character , calls chooseChar function and initializes player 1 and player 2
		std::cout << "Player " << 1 << " Choose Your Character" << std::endl;
		P1 = G.chooseCharacter();
		std::cout << "Player " << 2 << " Choose Your Character" << std::endl;
		P2 = G.chooseCharacter();

		//calls round function
		G.round(P1, P2);
	
		std::cout << std::endl;



	} while (M.continuePlaying() == 1);


}
