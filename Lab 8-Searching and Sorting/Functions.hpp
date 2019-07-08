/*
* Shifra Schectman
* May 27, 2018
* CS162 - Lab 8
* Functions Header File
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
class Functions
{
public:
	int search(std::vector<int>vect, int value);
	void showVector(std::vector<int>vect);
	void sort(std::vector<int> &vect);
	int binarySearch(std::vector<int> vect, int value);
};
#endif

