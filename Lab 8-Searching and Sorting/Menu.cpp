/*
* Shifra Schectman
* May 27, 2018
* CS162 - Lab 8
* Menu Source File
*/

#include "Menu.hpp"

/*
enterValue function: prompts the user to enter a target value and validates the input
*/
int Menu::enterValue()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "Enter target value." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			if (choice <100 && choice >100)
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