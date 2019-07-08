/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Medusa Class Header File
*/
#include "Character.hpp"
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character
{
public:
	Medusa();
	int attack();
	std::string getType();
};
#endif