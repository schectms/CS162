/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
* Character Class Header File
*/
#include <time.h>
#include <iostream>
#include <string>
#include <cstdlib>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
class Character
{
protected:
	std::string name;
	int strengthPoints;
	int armor;
	int defenseMin;
	int defenseMax;
	int attackMin;
	int attackMax;
	int damage;
public:
	Character();
	virtual std::string getType();
	int getStrengthPoints();
	void setStrengthPoints(int strengthPointsIn);
	int getArmor();
	virtual int attack();
	virtual int defense(int attack);
	std::string getName();
	void setName(std::string nameIn);
	int restoreDamage();
	virtual	~Character();
};
#endif
