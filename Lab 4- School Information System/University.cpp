/*
* Shifra Schectman
* April 29, 2018
* CS162 - Lab 4
* University Class Source File
*/

#include "University.hpp"

//default constructor that sets the name to Oregon State University
University::University()
{
	name = "Oregon State University";
}

//accessor function for name
std::string University::getName()
{
	return name;
}

//function that takes buildings as a parameter and adds them to a vector
void University::addBuilding(Building B1)
{
	buildings.push_back(B1);
}

//function that prints the information for the buildings
void University::printBuildings()
{
	std::cout << "BUILDINGS" << std::endl;
	std::cout << std::endl;
	//initialize loop to cycle through the buildings vector
	for (int i = 0; i < buildings.size(); i++)
	{
		//print building name
		std::cout << "Name: " << buildings.at(i).getName() << std::endl;
		//print building size
		std::cout << "Size: " << buildings.at(i).getSize() << std::endl;
		//print building address
		std::cout << "Address: " << buildings.at(i).getAddress() << std::endl;
		std::cout << std::endl;
	}
}

//function that takes people pointers as a parameter and adds them to a vector
void University::addPerson(Person* P1)
{
	people.push_back(P1);
}

//function that prints the information for the buildings
void University::printPeople()
{
	std::cout << "PEOPLE" << std::endl;
	std::cout << std::endl;
	//initialize loop to cycle through the people vector
	for (int i = 0; i < people.size(); i++)
	{
		//call printInfo to print their information
		people[i]->printInfo();
	}
}

//function that displays the menu options and returns the user's choice
int University::displayMenu()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "Oregon State University" << std::endl;
		std::cout << "Please select from the following options." << std::endl;
		std::cout << "1. Prints information about all the buildings." << std::endl;
		std::cout << "2. Prints information of everybody at the university." << std::endl;
		std::cout << "3. Choose a person to do work." << std::endl;
		std::cout << "4. Save the information to a file." << std::endl;
		std::cout << "5. Read saved information from a file." << std::endl;;
		std::cout << "6. Exit the program." << std::endl;

		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			if (choice < 1 || choice > 6)
			{
				system("clear");
			}
			else
			{
				errFlag = true;
			}
		}
		else
		{
			system("clear");
		}
	} while (errFlag == false);
	return choice;
}

//function that displays the list of people and returns the user's choice
int University::chooseWorker()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "Choose a person to do work" << std::endl;
		for (int i = 0; i < people.size(); i++)
		{
			std::cout << (i + 1) << ":" << people.at(i)->getName() << std::endl;
		}
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			if (choice <= 0 || choice > people.size())
			{
				system("clear");
			}
			else
			{
				errFlag = true;
			}
		}
		else
		{
			system("clear");
		}
	} while (errFlag == false);
	return choice;
}

//function that calls the doWork function on a person
void University::doWork()
{
	int choice=chooseWorker();
	choice--;
	people[choice]->doWork();
}

//function that reads the file of information
void University::readFile()
{
	//declares variable for line
	std::string line;
	//tries to open file
	std::ifstream inputFile("peopleRecord.txt");
	//if it is valid, displays file in console
	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			std::cout << line << std::endl;
		}
		//close file
		inputFile.close();
	}
	//if invalid, display error message
	else
	{
		std::cout << "No file by that name was found";
	}
}

//function to write information to file 
void University::writeFile()
{
	//declare output file
	std::ofstream outputFile;
	//open the file to append to it
	outputFile.open("peopleRecord.txt", std::ios_base::app);
	//print info to file
	outputFile <<"PEOPLE" << std::endl;
	outputFile << std::endl;
	//initialize loop to cycle through the people vector
	for (int i = 0; i < people.size(); i++)
	{
		//call printInfo function to print the info
		people[i]->printInfoToFile();
	}
	//close file
	outputFile.close();
}

//function that accepts information for new people
void University::addPeople()
{
	//initialize variables
	int age;
	std::string name;
	double GPA=0;
	double rating = 0;

	//call addPerson function to input validation
	int choice = addPerson("How many students would you like to add?", 0, 100);
	//initialize loop for amount of students to add
	for (int i = 0; i < choice; i++)
	{
		std::cin.ignore();
		//ask for user input information for student
		std::cout << "Student " << i + 1 << " Information:" << std::endl;
		
		std::cout << "Enter name" << std::endl;
		getline(std::cin, name);
		int age=addPerson("Enter age", 18, 100);
		bool valid=false;
		do
		{		
			std::cout << "Enter GPA" << std::endl;
			if(std::cin >>GPA) valid=true;
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter GPA" << std::endl;
				std::cin >> GPA;
			}

	} while (!valid || GPA <0.0 || GPA > 4.0);

		//create Student
		Student* S;
		S = new Student(name, age, GPA);
		//add Student to vector
		addPerson(S);
	}
	choice = addPerson("How many instructors would you like to add?", 0, 100);
	//initialize loop for amount of instructors to add
	for (int i = 0; i < choice; i++)
	{
		std::cin.ignore();
		std::cout << "Instructor " << i + 1 << " Information:" << std::endl;
		//ask for user input information for instructor
		std::cout << "Enter name" << std::endl;
		getline(std::cin, name);
		int age=addPerson("Enter age", 18, 100);
		bool valid = false;
		do {
			std::cout << "Enter Rating" << std::endl;
			if (std::cin >> rating) valid=true;
			else
			{
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Enter Rating" <<std::endl;
				std::cin >> rating;
			}

		} while (!valid || rating <0.0 ||rating >5.0);
	//create instructor
	Instructor* I;
	I = new Instructor(name, age, rating);
	//add instructor to vector
	addPerson(I);
}

}

//function that validates users choice for numberof ppl to add
int University::addPerson(std::string str, int min, int max)
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << str << std::endl;

		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			if (choice < min || choice > max)
			{
				system("clear");
			}
			else
			{
				errFlag = true;
			}
		}
		else
		{
			system("clear");
		}
	} while (errFlag == false);
	return choice;
}


//destructor to free memory
University::~University()
{
	//loops through people vector
	for (int i =0; i<people.size(); i++)
	{
		//deletes pointers
		delete people[i];
	}
	people.clear();
}
