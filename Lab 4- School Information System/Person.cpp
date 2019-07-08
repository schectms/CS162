/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Person Class Source File
*/

#include "Person.hpp"

//constructor
Person::Person(std::string nameIn, int ageIn)
{
	this->name = nameIn;
	this->age = ageIn;
}

//accessor function for name
std::string Person::getName()
{
	return name;
}

//accesor function for age
int Person::getAge()
{
	return age;
}

// virtual doWork function to be overriden in derived class
void Person::doWork()
{
}

// virtual printInfo function to be overriden in derived class
void Person::printInfo()
{
}

void Person::printInfoToFile()
{
}

