/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
* Blue Men Class Header File
*/
#include "Character.hpp"
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
public:
	BlueMen();
	void mob();
	std::string getType();
	int defense(int attack);
	~BlueMen();
};
#endif