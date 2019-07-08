/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Character Class Header File
*/
#include <time.h>
#include <iostream>
#include <cstdlib>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
class Character
{
protected:
	int strengthPoints;
	int armor;
	int defenseMin;
	int defenseMax;
	int attackMin;
	int attackMax;
public:
	Character();
	virtual std::string getType();
	int getStrengthPoints();
	void setStrengthPoints(int strengthPointsIn);
	int getArmor();
	virtual int attack();
	virtual int defense(int attack);
};
#endif
