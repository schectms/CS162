/*
* Shifra Schectman
* Lab 3
* Menu Class Source File
* April 22, 2018
*/
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Menu.hpp"
/*
* This function asks the user to 
* start the program or not
*/
int Menu::startProgram()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "War Game With Dice" << std::endl;
		std::cout << "1. Play game." << std::endl;
		std::cout << "2. Exit game." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			if (choice != 1 && choice != 2)
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

/*
* This function asks the user to
* select the number of rounds
*/
int Menu::numberOfRounds()
{
	bool errFlag = false;
	std::string input;
	int numberOfRounds;
	system("clear");
	do
	{
		std::cout << "Enter the number of rounds you want to play." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> numberOfRounds && !(sStream >> input))
		{
			if (numberOfRounds <1)
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
	return numberOfRounds;
}

/*
* This function asks the user to
* select the type of die for P1
*/
int Menu::typeOfDieP1()
{
	bool errFlag = false;
	std::string input;
	int typeOfDie;
	system("clear");
	do
	{
		std::cout << "Player One, choose your type of die." << std::endl;
		std::cout << "1. Regular Die" << std::endl;
		std::cout << "2. Loaded Die" << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> typeOfDie && !(sStream >> input))
		{
			if (typeOfDie != 1 && typeOfDie != 2)
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
	return typeOfDie;
}

/*
* This function asks the user to
* select the type of die for P2
*/
int Menu::typeOfDieP2()
{
	bool errFlag = false;
	std::string input;
	int typeOfDie;
	system("clear");
	do
	{
		std::cout << "Player Two, choose your type of die." << std::endl;
		std::cout << "1. Regular Die" << std::endl;
		std::cout << "2. Loaded Die" << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> typeOfDie && !(sStream >> input))
		{
			if (typeOfDie != 1 && typeOfDie != 2)
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
	return typeOfDie;
}

/*
* This function asks the user to
* select the number of sides for P1
*/
int Menu::numberOfSidesP1()
{
	bool errFlag = false;
	std::string input;
	int numberOfSides;
	system("clear");
	do
	{
		std::cout << "Player One, choose the number of sides for your die." << std::endl;
		std::cout << "Enter the number of sides (4-20)" << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> numberOfSides && !(sStream >> input))
		{
			if (numberOfSides<4 || numberOfSides>20)
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
	return numberOfSides;
}

/*
* This function asks the user to
* select the number of sides for P2
*/
int Menu::numberOfSidesP2()
{
	bool errFlag = false;
	std::string input;
	int numberOfSides;
	system("clear");
	do
	{
		std::cout << "Player Two, choose the number of sides for your die." << std::endl;
		std::cout << "Enter the number of sides (4-20)" << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> numberOfSides && !(sStream >> input))
		{
			if (numberOfSides<4 || numberOfSides>20)
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
	return numberOfSides;
}


