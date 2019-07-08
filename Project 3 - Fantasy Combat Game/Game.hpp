/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Game Class Header File
*/
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
public:
	Character *chooseCharacter();
	void round(Character *P1, Character *P2);


	
};
#endif

