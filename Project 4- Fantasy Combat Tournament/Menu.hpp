/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
* Menu Class Header File
*/

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#ifndef MENU_HPP
#define MENU_HPP
class Menu
{
public:
	int continuePlaying();
	int chooseCharacter();
	int numberOfPlayers();
	std::string enterName();
	int displayLosers();
};
#endif

