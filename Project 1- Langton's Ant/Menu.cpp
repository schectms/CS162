/*
* Shifra Schectman
* Project 1 Menu Specification File
* April 15, 2018
*/

#include "Menu.hpp"
#include <iostream>
#include <cstdlib>

//ask user if they would like to start program
int Menu::startProgram()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "Langton's Ant" << std::endl;
		std::cout << "1. Start simulation." << std::endl;
		std::cout << "2. Quit the program." << std::endl;
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

//ask user for number of columns
int Menu::getNumberOfCols()
{
	bool errFlag = false;
	std::string input;
	int numberOfCols;
	system("clear");
	do
	{
		std::cout << "Enter the number of columns." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> numberOfCols && !(sStream >> input))
		{
			if (numberOfCols <= 1 || numberOfCols>100)
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
	return numberOfCols;
}

//ask user for number of rows
int Menu::getNumberOfRows()
{
	bool errFlag = false;
	std::string input;
	int numberOfRows;
	system("clear");
	do
	{
		std::cout << "Enter the number of rows." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> numberOfRows && !(sStream >> input))
		{
			if (numberOfRows <= 1 || numberOfRows>100)
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
	return numberOfRows;
}

//ask user for number of steps
int Menu::getNumberOfSteps()
{
	bool errFlag = false;
	std::string input;
	int numberOfSteps;
	system("clear");
	do
	{
		std::cout << "Enter the number of steps." << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> numberOfSteps && !(sStream >> input))
		{
			if (numberOfSteps<1 || numberOfSteps>50)
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
	return numberOfSteps;
}

//ask user for starting row
int Menu::getStartingRow(int numberOfRows)
{
	bool errFlag = false;
	std::string input;
	int startingRow;
	system("clear");
	do
	{
		std::cout << "Enter the starting row." << std::endl;
		std::cout << "(The top row is the 0th row.)" << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> startingRow && !(sStream >> input))
		{
			if (startingRow >= numberOfRows || startingRow<0)
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
	return startingRow;
}

//ask user for starting column
int Menu::getStartingCol(int numberOfCols)
{
	bool errFlag = false;
	std::string input;
	int startingCol;
	system("clear");
	do
	{
		std::cout << "Enter the starting column." << std::endl;
		std::cout << "(The left-most column is the 0th column.)" << std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> startingCol && !(sStream >> input))
		{
			if (startingCol >= numberOfCols || startingCol<0)
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
	return startingCol;
}






