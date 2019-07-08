/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Instructor Class Header File
*/

#include <iomanip>
#include "Person.hpp"

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

class Instructor :public Person
{
private:
	double rating;
public:
	Instructor(std::string nameIn, int ageIn, double ratingIn);
	double getRating();
	virtual void doWork();
	virtual void printInfo();
	void printInfoToFile();
};
#endif
