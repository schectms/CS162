/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
* Barbarian Class Source File
*/

#include "Barbarian.hpp"

/*
Default Constructor that sets the data member values for barbarian
*/
Barbarian::Barbarian() : Character()
{
	strengthPoints = 12;
	armor = 0;
	attackMin = 2;
	attackMax = 12;
	defenseMin = 2;
	defenseMax = 12;
}

/*
getType function: returns the type of char
*/
std::string Barbarian::getType()
{
	return "Barbarian";
}

Barbarian::~Barbarian()
{
}
