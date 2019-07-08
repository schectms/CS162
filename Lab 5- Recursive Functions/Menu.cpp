/*
* Shifra Schectman
* May 6, 2018
* CS162 - Lab 5
* Menu Class Source File
*/

#include "Menu.hpp"

/*
This function displays a menu of options to the user and 
ask them to choose one.
*/
int Menu::chooseFunction()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "Choose from the following menu options." << std::endl;
		std::cout << "1. Print the reverse of a string." << std::endl;
		std::cout << "2. Print the sum of integers." << std::endl;
		std::cout << "3. Print the triangular number." << std::endl;
		std::cout << "4. Exit program." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			if (choice <1 ||choice >4)
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
This function ask the user to input an integer and 
makes sure the number is within a range
*/
int Menu::inputInteger(std::string str, int min, int max)
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << str <<std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			if (choice <min || choice >max)
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
