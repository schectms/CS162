/*
* Shifra Schectman
* Lab 3
* Game Class Header File
* April 22, 2018
*/
#include "Die.hpp"
#include "Menu.hpp"
#include <iostream>
#ifndef GAME_HPP
#define GAME_HPP
class Game
{
private:
	Menu M;
	Die *P1;
	Die *P2;
	int scoreP1 = 0;
	int scoreP2 = 0;
	
public:
	Game();
	void playGame();
	void displayScore();
	~Game();
};
#endif

