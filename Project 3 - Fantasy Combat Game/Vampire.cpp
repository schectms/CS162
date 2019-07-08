/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Vampire Class Source File
*/

#include "Vampire.hpp"

/*
Default Constructor that sets the data member values for vampire
*/
Vampire::Vampire() : Character()
{
	strengthPoints = 18;
	armor = 3;
	attackMin = 1;
	attackMax = 12;
	defenseMin = 1;
	defenseMax = 6;
}
/*
charm function: 50% chance that the vampire will not be attacked
*/
bool Vampire::charm()
{
	//randomly generates number between 1 and 2
	int rnd = rand() % 2 + 1;
	//if 1, vampires charm set to true
	if (rnd == 1)
	{
		std::cout << "Vampire has used charm and cannot be attacked." << std::endl;
		return true;
	}
	//otherwise false
	else
	{
		return false;
	}
}

/*
getType function: returns the type of char
*/
std::string Vampire::getType()
{
	return "Vampire";
}

/*
defense function takes the damage attacked as a paramater, and calculate the actual damage inflicted, and apply that damage to the defender’s strength points
*/
int Vampire::defense(int attack)
{
	//define damage
	int damage;
	//if charm, set damage to 0
	if (charm())
	{
		damage = 0;
	}
	//if attack is -1
	else if (attack == -1)
	{
		//set damage to amount of strength points
		damage = getStrengthPoints();
		//set strength points to 0
		setStrengthPoints(0);
	}
	else
	{
		//initialize defense to random number generated from characters dice
		int defense = defenseMin + rand() % ((defenseMax + 1) - defenseMin);
		//display die rolls of attacker and defender
		std::cout << "Attacker has spun a " << attack << " and " << "Defender has spun a " << defense << std::endl;
		//if attack is more than or equal to defense, set damage to 0
		if (attack >= defense)
		{
			//if attack -armor is less than 0, calculate damage inflicted and set strength points
			if (attack - defense - armor < 0)
			{
				damage = 0;
			}
			else
			{
				damage = attack - defense - armor;
				setStrengthPoints(getStrengthPoints() - damage);
			}
		}
		//otherwise, set damage to 0
		else
		{
			damage = 0;
		}
	}
	//display damage inflicted and current strength
	std::cout << "Defender has sustained " << damage << " damage and currently has " << getStrengthPoints() << " strength points" << std::endl;
	return damage;
}
