/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
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
	~Barbarian();
};
#endif

