/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Vampire Class Header File
*/

#include "Character.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Character
{
public:
	Vampire();
	bool charm();
	std::string getType();
	int defense(int attack);
};
#endif

