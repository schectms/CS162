/*
* Shifra Schectman
* May 6, 2018
* CS162 - Lab 5
* Sum Function Source File
*/

#include "sum.hpp"

/*
This function takes an array and number of elements in it as a parameter
and returns the sum of the integers in the array
*/
int sum(int array[], int numberOfElements)
{
	//base case(no elements in the array)
	if (numberOfElements == 0)
	{
		return 0;
	}
	//otherwise uses recursion to call the sum function
	else
	{
		return array[numberOfElements - 1] + sum(array, (numberOfElements - 1));
	}

}
