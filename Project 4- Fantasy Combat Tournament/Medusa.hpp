/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
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
	~Medusa();
};
#endif