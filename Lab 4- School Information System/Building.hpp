/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Building Class Header File
*/

#include <iostream>
#include <string>

#ifndef BUILDING_HPP
#define BUILDING_HPP

class Building
{
private:
	std::string name;
	int size;
	std::string address;

public:
	Building(std::string nameIn, int sizeIn, std::string addressIn);
	std::string getName();
	int getSize();
	std::string getAddress();
};

#endif
