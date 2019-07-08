/*
* Shifra Schectman
* May 6, 2018
* CS162 - Lab 5
* Main File
*/

#include <iostream>
#include "Menu.hpp"
#include "reverse.hpp"
#include "triangle.hpp"
#include "sum.hpp"

int main()
{
	//create instance of Menu
	Menu M;
	//initiate variable for choice
	int choice;
	//initiate loop to display menu until the user chooses to exit
	do
	{
	//sets the choice
	choice = M.chooseFunction();
	
		//if user selects 1
		if (choice == 1)
		{
			//initiate string variable
			std::string str;
			//prompt the user to input a string
			std::cout << "Enter a string and I will reverse it for you." << std::endl;
			getline(std::cin, str);
			//reverse the string
			std::cout << "The reverse of the string is ";
			reverse(str);
		}
		//if the user selects 2
		else if (choice == 2)
		{
			//prompt the user for numer of integers and store in variable
			int numberOfIntegers = M.inputInteger("How many integers would you like to add?", 0, 1000000);
			//allocate memory for array
			int* array = new int[numberOfIntegers];
			//initialize loop which prompts the user for each number
			for (int i = 0; i < numberOfIntegers; i++)
			{
				array[i] = M.inputInteger("Enter an integer", -1000000, 1000000);
			}
			//sum the numbers in the array
			std::cout << "The sum of the array is " << sum(array, numberOfIntegers) << std::endl;
			//delete memory
			delete[]array;
		}
		//if the user selects 3
		else if (choice == 3)
		{
			//prompt the user to input a number and strore in variable tr
			int tr = M.inputInteger("Enter a number and I will return the triangular number.",1, 1000);
			//display the triangular number at that position
			std::cout << "Triangular number " << tr << " is " << triangle(tr) << std::endl;
		}
		//if the user selects 4
		else
		{
			//display message that program is exiting
			std::cout << "Exiting program." << std::endl;
		}
	} while (choice != 4);	
}
