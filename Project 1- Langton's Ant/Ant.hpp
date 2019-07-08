/*
* Shifra Schectman
* Project 1 Ant Header File
* April 15, 2018
*/

#ifndef ANT_HPP
#define ANT_HPP
#include <string>

enum Orientation { North, East, South, West };

class Ant
{
private:
	Orientation direction;
	int antRow;
	int antCol;
	std::string color;

public:
	Ant(Orientation directionIn, int startingRow, int startingCol, std::string colorIn);
	Orientation getOrientation();
	void setOrientation(Orientation directionIn);
	int getAntRow();
	int getAntCol();
	bool setAntRow(int antRow, int numberOfRows);
	bool setAntCol(int antCol, int numberOfCols);
	std::string getColor();
	void setColor(std::string colorIn);
};
#endif
