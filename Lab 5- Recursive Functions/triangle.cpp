/*
* Shifra Schectman
* May 6, 2018
* CS162 - Lab 5
* Triangular Function Source File
*/

#include "triangle.hpp"

/*
This function takes a number as a parameter and returns the 
triangular number at that position
*/
int triangle(int N)
{
	//base case(first triangular number)
	if (N == 1)
	{
		//returns 1
		return 1;
	}
	//otherwise, uses recursion to call triangle function 
	else
	{
		return (N)+triangle(N - 1);
	}

}
