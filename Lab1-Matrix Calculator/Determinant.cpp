/*
 * Shifra Schectman
 * January 14, 2017
 * this function takes a pointer to the matrix array and the size as a parameter and
 * calculates the determinant of the matrix.
 */
#include <iostream>
#include "Determinant.hpp"

int determinant(int** matrix,int size)
{
	int det=0;
	if(size==2)
	{
		det=
			matrix[0][0]*matrix[1][1]-
			matrix[0][1]*matrix[1][0];
	}
	else if(size==3)
	{
		det=
			matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1])-
			matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0])+
			matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);	
	}
	return det;
}

