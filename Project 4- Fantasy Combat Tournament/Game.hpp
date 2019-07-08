/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
* Game Class Header File
*/
#include "DynIntQueue.hpp"
#include "Menu.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#ifndef GAME_HPP
#define GAME_HPP
class Game
{
private:
	Menu M;
	Character* P1;
	Character* P2;
	DynIntQueue Team1;
	DynIntQueue Team2;
	DynIntQueue Losers;
	int P1Score=0;
	int P2Score=0;
public:
	Character *chooseCharacter();
	void round(Character *P1, Character *P2);
	void tournament();
	void runGame();
	void displayScore();
};
#endif

