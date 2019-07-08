/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
* Source File
*/

#include "Game.hpp"

int main()
{
	//seed random
	srand(time(NULL));
	Menu M1;
	do{
		//declare Game
		Game G;
		//call runGame function
		G.runGame();
	}
	while (M1.continuePlaying()==1);
}
