/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Building Class Source File
*/

#include "Building.hpp"

//constructor that sets the name, size and address of the buildings
Building::Building(std::string nameIn, int sizeIn, std::string addressIn)
{
	name = nameIn;
	size = sizeIn;
	address = addressIn;
}

//accessor function for name
std::string Building::getName()
{
	return name;
}

//accessor function for size
int Building::getSize()
{
	return size;
}

//accessor function for address
std::string Building::getAddress()
{
	return address;
}
