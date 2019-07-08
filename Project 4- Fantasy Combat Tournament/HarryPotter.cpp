/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
* Harry Potter Source File
*/

#include "HarryPotter.hpp"

/*
Default Constructor that sets the data member values for harry potter
*/
HarryPotter::HarryPotter() :Character()
{
	strengthPoints = 10;
	armor = 0;
	attackMin = 2;
	attackMax = 12;
	defenseMin = 2;
	defenseMax = 12;
	resurrected = false;
}

/*
Hogwarts function checks if resurrected is false and strength points are less than 0 and resurrects harry
*/
bool HarryPotter::Hogwarts()
{
	//if harry is dead has never been resurrected
	if (!resurrected && strengthPoints <= 0)
	{
		//display message
		std::cout << "Harry Potter comes back to life" << std::endl;
		//set reserructed to true
		resurrected = true;
		//set strength points to 10
		setStrengthPoints(10);
	}
	//if harry is dead but has been ressurected, display message
	else if (resurrected == true && strengthPoints <= 0)
	{
		std::cout << "Harry Potter has already been resurrected once." << std::endl;
	}
	return resurrected;
}


/*
getType function: returns the type of char
*/
std::string HarryPotter::getType()
{
	return "Harry Potter";
}

/*
defense function takes the damage attacked as a paramater, and calculate the actual damage inflicted, and apply that damage to the defenderís strength points
*/
int HarryPotter::defense(int attack)
{
	//declare damage variable
	//int damage;
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
	//call Hogwarts function
	Hogwarts();
	//return damage
	return damage;
}

HarryPotter::~HarryPotter()
{
}

