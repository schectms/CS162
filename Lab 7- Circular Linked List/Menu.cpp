/*
* Shifra Schectman
* May 20, 2018
* CS162 - Lab 7
* Menu Class Source File
*/

#include "Menu.hpp"

/*
continuePlaying
asks the user if they want to continue and returns 1 if yes, 2 if no
*/
int Menu::continuePlaying()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "1. Continue." << std::endl;
		std::cout << "2. Exit the program." << std::endl;
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
chooseFunction
asks the user which function they want to choose and returns it
*/
int Menu::chooseFunction()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "1. Add a value to the back of queue." << std::endl;
		std::cout << "2. Display the front value." << std::endl;
		std::cout << "3. Remove the front node." << std::endl;
		std::cout << "4. Display the queue's content." << std::endl;
		std::cout << "5. Exit." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			if (choice < 1 && choice >5)
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
enterNumber
asks the user to enter a number and returns it
*/
int Menu::enterNumber()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "Enter a number to insert into the list." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			return choice;
		}
		else
		{
			system("clear");
		}
	} while (errFlag == false);
	return choice;
}
