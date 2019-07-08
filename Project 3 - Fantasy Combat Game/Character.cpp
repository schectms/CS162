/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Character Class Source File
*/

#include "Character.hpp"

/*
default constructor for character
*/
Character::Character()
{
}

/*
getType function: returns the type of char
*/
std::string Character::getType()
{
	 return 0; 
}

/*
getStrengthPoints function: returns the strength points
*/
int Character::getStrengthPoints()
{
		return strengthPoints;
}

/*
setstrengthpoints fucntion: mutator function for strength points
*/
void Character::setStrengthPoints(int strengthPointsIn)
{
	strengthPoints = strengthPointsIn;
}

/*
get armor: accessor function for armor
*/
int Character::getArmor()
{
	return armor;
}

/*
attack fucntion returnd the die roll for attack
*/
int Character::attack()
{
	return attackMin + rand() % ((attackMax + 1) - attackMin);
}

/*
defense function takes the damage attacked as a paramater, and calculate the actual damage inflicted, and apply that damage to the defender’s strength points
*/
int Character::defense(int attack)
{
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