/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Harry Potter Class Header File
*/
#include "Character.hpp"
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter :public Character
{
private:
	bool resurrected;
public:
	HarryPotter();
	bool Hogwarts();
	std::string getType();
	int defense(int attack);

};
#endif
