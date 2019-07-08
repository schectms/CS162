/*
* Shifra Schectman
* Project 1 Menu Header File
* April 15, 2018
*/

#ifndef MENU_HPP
#define MENU_HPP
#include <sstream>

class Menu
{
private:
public:
	int startProgram();
	int getNumberOfRows();
	int getNumberOfCols();
	int getNumberOfSteps();
	int getStartingRow(int numberOfRows);
	int getStartingCol(int numberOfCols);

};


#endif
