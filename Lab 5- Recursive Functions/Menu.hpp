/*
* Shifra Schectman
* May 6, 2018
* CS162 - Lab 5
* Menu Class Header File
*/

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

#ifndef CLASS_HPP
#define CLASS_HPP
class Menu
{
public:
	int chooseFunction();
	int inputInteger(std::string input, int min, int max);
};
#endif
