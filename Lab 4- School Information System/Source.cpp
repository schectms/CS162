/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Main File
*/

#include <cstdlib>
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "University.hpp"

int main()
{
	srand(time(NULL));
	//create University object
	University OSU;

	//create 5 Building Objects
	Building B1("The Gem", 89866, "155 NW KINGS BLVD");
	Building B2("Shepard Hall", 11512, "28645 E. HWY 34");
	Building B3("Jefferson Street Bldg", 28361, "3731 SW JEFFERSON");
	Building B4("Child Care Center", 12347, "1262 SW ADAMS AVE");
	Building B5("Kidder Hall", 81329, "2000 SW CAMPUS WAY");

	//add buildings to vector
	OSU.addBuilding(B1);
	OSU.addBuilding(B2);
	OSU.addBuilding(B3);
	OSU.addBuilding(B4);
	OSU.addBuilding(B5);

	//allocate memory for and create 5 Person objects
	Student* P1;
	P1=new Student("Shifra Schectman", 21, 4.0);
	Instructor* P2;
	P2=new Instructor("Matthew Britt", 30, 5.0);
	Instructor* P3;
	P3= new Instructor("Luyao Zhang", 40, 5.0);
	Student* P4;
	P4= new Student("Justin Bieber", 24, 3.5);
	Instructor *P5;
	P5=new Instructor("Donald Trump", 71, 2.0);

	//add people to vector
	OSU.addPerson(P1);
	OSU.addPerson(P2);
	OSU.addPerson(P3);
	OSU.addPerson(P4);
	OSU.addPerson(P5);

	//ask user if he would like to add people
	OSU.addPeople();
	//ask user to choose from Menu options
	int choice = OSU.displayMenu();
	if (choice ==1)
	{
		//call printBuildings function
		OSU.printBuildings();
		return 0;
	}
	else if (choice == 2)
	{
		//call printPeople function
		OSU.printPeople();
		return 0;
	}
	else if (choice == 3)
	{
		//call doWork function
		OSU.doWork();
		return 0;
	}
	else if (choice == 4)
	{
		//call write file function
		OSU.writeFile();
		return 0;
	}
	else if (choice == 5)
	{
		//call readFile function
		OSU.readFile();
		return 0;
	}
	else
	{
		//exit program and notify user
		std::cout << "Program quit." << std::endl;
		return 0;
	}
}
