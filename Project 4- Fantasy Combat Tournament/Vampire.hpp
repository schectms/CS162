/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
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
	~Vampire();
};
#endif

