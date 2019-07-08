/*
* Shifra Schectman
* May 6, 2018
* CS162 - Lab 5
* Reverse Function Source File
*/

#include "reverse.hpp"

/*
This function takes a string as a parameter and prints the reverse
*/
void reverse(std::string str)
{
	//base case(empty string)
	if (str.length() == 0)
	{
		std::cout << std::endl;
	}
	//otherwise uses recursion and calls reverse function
	else
	{
		std::cout << (str[str.length() - 1]);
		reverse(str.substr(0, str.length() - 1));
	}
}