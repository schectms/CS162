/*
* Shifra Schectman
* Project 1 Ant Specification File
* April 15, 2018
*/
#include <iostream>
#include "Ant.hpp"

Ant::Ant(Orientation directionIn, int startingRow, int startingCol, std::string colorIn)
{
	direction = directionIn;
	antRow = startingRow;
	antCol = startingCol;
	color = colorIn;

}

Orientation Ant::getOrientation()
{
	return direction;
}

void Ant::setOrientation(Orientation directionIn)
{
	direction = directionIn;
}

int Ant::getAntRow()
{
	return antRow;
}

int Ant::getAntCol()
{
	return antCol;
}

bool Ant::setAntCol(int antColIn, int numberOfCols)
{
	if (antColIn < 0 || antColIn >= numberOfCols)
	{
		return false;
	}
	else
	{
		antCol = antColIn;
		return antCol;
	}
}

bool Ant::setAntRow(int antRowIn, int numberOfRows)
{
	if (antRowIn< 0 || antRowIn >= numberOfRows)
	{
		return false;
	}

	else
	{
		antRow = antRowIn;
		return antRow;
	}
}

std::string Ant::getColor()
{
	return color;
}

void Ant::setColor(std::string colorIn)
{
	color = colorIn;
}
