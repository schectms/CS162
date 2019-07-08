/*
* Shifra Schectman
* May 13, 2018
* CS162 - Lab 6
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
		std::cout << "1. Add a new node to the head." << std::endl;
		std::cout << "2. Add a new node to the tail." << std::endl;
		std::cout << "3. Delete the first node in the list." << std::endl;
		std::cout << "4. Delete the last node in the list." << std::endl;
		std::cout << "5. Traverse the list reversely." << std::endl;
		std::cout << "6. Print the value of the Node the head is pointing to." << std::endl;
		std::cout << "7. Print the value of the Node the tail is pointing to." << std::endl;
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


/*
textfile
asks the user if they want to use textfile and returns 1 if yes, 2 if no
*/
int Menu::textfile()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "Would you like to create the linked list from textfile 'ec'?" << std::endl;
		std::cout << "1. Yes." << std::endl;
		std::cout << "2. No." << std::endl;
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
