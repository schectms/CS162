/*
 * Shifra Schectman
 * January 15, 2018
 * Lab1: Matrix Calculator
 * This program displays the matrix and the determinant of a matrix.
 */  
#include <iostream>
#include "Matrix.hpp"
#include "Determinant.hpp"

int main()
{
	int size=0;
	//prompt the user to input the size of the matrix
	std::cout <<"Choose the size of the matrix"<<std::endl;
	std::cout <<"Enter 2 for a 2x2 and 3 for a 3x3" << std::endl;
	std::cin >> size;
	//dynamically allocate memory for the matrix
	int** matrix =new int*[size];
	for(int i=0; i<size; ++i)
	{
		matrix[i]=new int[size];
	}
	//display matrix and determinant
	readMatrix(matrix, size);
	std::cout<<std::endl;
	std::cout<<"Determinant:" << std::endl;
	std::cout <<determinant(matrix, size)<<std::endl;
	//free the dynamically allocated memory
	for(int i=0; i<size; ++i)
	{
		delete[] matrix[i];
	}
		delete[] matrix;
	
	return 0;
}

