/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Blue Men Class Source File
*/

#include "BlueMen.hpp"

/*
Default Constructor that sets the data member values for blue men
*/
BlueMen::BlueMen() : Character()
{
	strengthPoints = 12;
	armor = 3;
	attackMin = 2;
	attackMax = 20;
	defenseMin = 3;
	defenseMax = 18;
}

/*
mob function that decreases defense die roll max based on strength points
*/
void BlueMen::mob()
{
	//if 4-8, set min to 2 and max to 12
	if (strengthPoints < 8 && strengthPoints>4)
	{
		defenseMin = 2;
		defenseMax = 12;
	}
	//if less than 4,set min to 1 and max to 6
	else if (strengthPoints < 4)
	{
		defenseMin = 1;
		defenseMax = 6;
	}
}

/*
getType function: returns the type of char
*/
std::string BlueMen::getType()
{
	return "Blue Men";
}

/*
defense function takes the damage attacked as a paramater, and calculate the actual damage inflicted, and apply that damage to the defender’s strength points
*/



int BlueMen::defense(int attack)
{
	//call mob function
	mob();
	//define damage
	//declare damage variable
	int damage;
	//spin die for damage
	int defense = defenseMin + rand() % ((defenseMax + 1) - defenseMin);
	//if attack is -1, set damage to strength points and set strength points to 0
	if (attack == -1)
	{
		damage = getStrengthPoints();
		setStrengthPoints(0);
	}

	//if attack is more than defense, calcualte damage inflicted andset strength points
	else if (attack >= defense)
	{
		//display die rolls
		std::cout << "Attacker has spun a " << attack << " and " << "Defender has spun a " << defense << std::endl;
		//calculate damage
		//if  damage will be -
		if (attack - defense - armor < 0)
		{
			//set damage to 0
			damage = 0;
		}
		else
		{
			damage = attack - defense - armor;
			setStrengthPoints(getStrengthPoints() - damage);
		}
	}
	//if damage will be -, display message 
	else
	{
		std::cout << "Attacker has spun a " << attack << " and " << "Defender has spun a " << defense << std::endl;
		damage = 0;
	}

	//display damage inflicted
	std::cout << "Defender has sustained " << damage << " damage and currently has " << getStrengthPoints() << " strength points" << std::endl;
	//return damage
	return damage;
}



