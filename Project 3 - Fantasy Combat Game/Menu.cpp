/*
* Shifra Schectman
* May 13, 2018
* CS162 - Project 3
* Menu Class Source File
*/
#include "Menu.hpp"
/*
continue playing function that asks the user if they would like to continue or not
*/
int Menu::continuePlaying()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "1. Play Again." << std::endl;
		std::cout << "2. Exit the game." << std::endl;
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
choose character function that asks the user which character they want to choose
*/
int Menu::chooseCharacter()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "1. Vampire." << std::endl;
		std::cout << "2. Barbarian." << std::endl;
		std::cout << "3. Blue Men." << std::endl;
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Harry Potter." << std::endl;
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

