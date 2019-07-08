/*
* Shifra Schectman
* Lab 3 
* War Game with Dice Design
* April 22, 2018
*/
#include <iostream>
#include <cstdlib>
#include "Menu.hpp"
#include "Die.hpp"
#include "Game.hpp"

int main()
{
	Menu M;
	if (M.startProgram() == 1)
	{
		Game G;
		G.playGame();
		G.displayScore();
	}
	else
	{
		std::cout << "Quitting Game" << std::endl;
	}
		
}

