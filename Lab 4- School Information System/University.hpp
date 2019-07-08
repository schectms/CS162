/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* University Class Header File
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "Person.hpp"
#include "Building.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP
class University
{
private:
	std::string name;
	std::vector<Building> buildings;
	std::vector<Person*> people;
public:
	University();
	std::string getName();
	void addBuilding(Building B1);
	void printBuildings();
	void addPerson(Person* P1);
	void printPeople();
	int displayMenu();
	int chooseWorker();
	void doWork();
	void readFile();
	void writeFile();
	void addPeople();
	int addPerson(std::string str, int min, int max);
	~University();
};
#endif
