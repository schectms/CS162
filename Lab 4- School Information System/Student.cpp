/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Student Class Header File
*/

#include "Student.hpp"

//constructor that sets the name, age and gpa of the student
Student::Student(std::string nameIn, int ageIn, double GPAIn) : Person(nameIn, ageIn)
{
	this->name = nameIn;
	this->age = ageIn;
	this->GPA = GPAIn;
}

//accessor function for GPA
double Student::getGPA()
{
	return GPA;
}

//function that overrides the base class, and diplays work done by student
void Student::doWork()
{
	//generates random number of hours
	int work = rand() % 8 + 1;
	//display work done
	std::cout << name << " did " << work << " hours of homework.";
}

//function that overrides the base class, and diplays information of student
void Student::printInfo()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "GPA " << GPA << std::endl;
	std::cout << std::endl;
}

//function that overrides the base class, and prints information to file
void Student::printInfoToFile()
{
	//declare output file
	std::ofstream outputFile;
	//open output file
	outputFile.open("peopleRecord.txt", std::ios_base::app);
	//send info to file
	outputFile << "Name: " << name << std::endl;
	outputFile << "Age: " << age << std::endl;
	//format the GPA
	outputFile << std::fixed << std::setprecision(1);
	outputFile << "GPA: " << GPA << std::endl;
	outputFile << std::endl;
	//close file
	outputFile.close();
}
