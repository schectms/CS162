/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Student Class Header File
*/
#include <iomanip>

#include "Person.hpp"

#ifndef STUDENT_HPP
#define STUDENT_HPP
class Student :public Person
{
private:
	double GPA;
public:
	Student(std::string nameIn, int ageIn, double GPAIn);
	double getGPA();
	void doWork();
	void printInfo();
	void printInfoToFile();
};
#endif

