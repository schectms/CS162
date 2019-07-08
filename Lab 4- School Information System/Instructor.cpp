/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* Instructor Class Source File
*/

#include "Instructor.hpp"

//constructor that sets the name, age and rating of the instructor
Instructor::Instructor(std::string nameIn, int ageIn, double ratingIn) : Person(nameIn, ageIn)
{
	this->name = nameIn;
	this->age = ageIn;
	this->rating = ratingIn;
}

//accessor function for rating
double Instructor::getRating()
{
	return rating;
}

//function that overrides the base class, and diplays work done by instructor
void Instructor::doWork()
{
	//generates random number of hours
	int work = rand() % 8 + 1;
	//displays work done
	std::cout << name << " graded papers for " << work << " hours." <<std::endl;

}

//function that overrides the base class, and diplays information of instructor
void Instructor::printInfo()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Rating " << rating << std::endl;
	std::cout << std::endl;
}

void Instructor::printInfoToFile()
{
	std::ofstream outputFile;
	outputFile.open("peopleRecord.txt", std::ios_base::app);
	outputFile << "Name: " << name << std::endl;
	outputFile << "Age: " << age << std::endl;
	outputFile << std::fixed << std::setprecision(1);
	outputFile << "Rating " << rating << std::endl;
	outputFile << std::endl;
	outputFile.close();
}
