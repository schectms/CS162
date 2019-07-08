/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Person Class Header File
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#ifndef PERSON_HPP
#define PERSON_HPP
class Person
{
protected:
	std::string name;
	int age;
public:
	Person(std::string nameIn, int ageIn);
	std::string getName();
	int getAge();
	virtual void doWork();
	virtual void printInfo();
	virtual void printInfoToFile();
};
#endif



