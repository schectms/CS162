/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Medusa Class Source File
*/

#include "Medusa.hpp"

/*
Default Constructor that sets the data member values for medusa
*/
Medusa::Medusa() : Character()
{
	strengthPoints = 8;
	armor = 3;
	attackMin = 2;
	attackMax = 12;
	defenseMin = 1;
	defenseMax = 6;
}

/*
attack function returns the damage attacked
*/
int Medusa::attack()
{
	//initialize attack to random number generated from characters dice
	int attc = attackMin + rand() % ((attackMax + 1) - attackMin);
	//if 12, activate glare and returns -1
	if (attc == 12)
	{
		std::cout << "Glare has been used" << std::endl;
		return -1;
	}
	//otherwise, returns attack number
	else
	{
		return attc;
	}

}

/*
getType function: returns the type of char
*/
std::string Medusa::getType()
{
	return "Medusa";
}

