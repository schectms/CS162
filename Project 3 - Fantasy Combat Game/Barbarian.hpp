/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Barbarian Class Header File
*/
#include "Character.hpp"
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Character
{
public:
	Barbarian();
	std::string getType();
};
#endif

