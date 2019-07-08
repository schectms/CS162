/*
* Shifra Schectman
* June 3, 2018
* CS162 - Lab 9
* Menu Class Source File
*/

#include "Menu.hpp"
/*
enterNumber: asks the user to enter a number and validates the input
*/
int Menu::enterNumber(std::string str)
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
			if (choice < 0 && choice > 100)
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

std::string Menu::enterString()
{
	std::cout << "Enter a string to turn into a palindrome: " << std::endl;
	std::string palindrome;
	getline(std::cin, palindrome);
	return palindrome;
}
