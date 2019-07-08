/*
* Shifra Schectman
* Project 1 Main File
* April 15, 2018
* This program runs a simulation of Langton's Ant
*/

#include <iostream>
#include <cstdlib>
#include <time.h> 
#include "Ant.hpp"
#include "Menu.hpp"


//prototype for print board function
void printBoard(char** board, int numberOfRows, int numberOfCols);

int main()
{
	//create Menu
	Menu M;
	int startingRow = 0;
	int startingCol=0;
	//if press 2, quit program
	if (M.startProgram() == 2)
	{
		std::cout << "Program quit." << std::endl;
	}
	//if press 1, start simulation
	else
	{
		//get information from user
		int numberOfRows = M.getNumberOfRows();
		int numberOfCols = M.getNumberOfCols();
		int numberOfSteps = M.getNumberOfSteps();
		if (M.randomStart() == 1)
		{
			std::cout << "Ant will be placed randomly" << std::endl;
			srand(time(NULL));
			int startingRow = rand() % numberOfRows;
			int startingCol = rand() % numberOfCols;
			std::cout << "Ant was placed at row:" << startingRow << "and column:" << startingCol << std::endl;

		}
		else
		{
			int startingRow = M.getStartingRow(numberOfRows);
			int startingCol = M.getStartingCol(numberOfCols);
		}

		//dynamically allocate memory for board
		char** board = new char*[numberOfRows];
		for (int i = 0; i < numberOfRows; ++i)
		{
			board[i] = new char[numberOfCols];
		}

		//initialize board to empty characters
		for (int i = 0; i < numberOfRows; ++i)
		{
				for (int j = 0; j < numberOfCols; ++j)
				{
					board[i][j] = (' ');
				}
		}

		//create Ant
		Ant A(North, startingRow, startingCol, "white");

		//set ant row and ant column
		int antRow = A.getAntRow();
		int antCol = A.getAntCol();

		//place ant on board
		board[antRow][antCol] = '*';
		
		//print board
		printBoard(board, numberOfRows, numberOfCols);

		//loop through number of steps chosen
		for (int i = 0; i < numberOfSteps; ++i)
		{
			//space is white and orientation is North
			if (A.getColor() == "white" && A.getOrientation() == North)
			{
				board[A.getAntRow()][A.getAntCol()] = '#';
				A.setOrientation(East);
				if (!A.setAntCol(++antCol, numberOfCols))
				{
					A.setAntCol(0, numberOfCols);
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				else
				{
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				board[A.getAntRow()][A.getAntCol()] = '*';
			}

			//space is white and orientation is east
			else if (A.getColor() == "white" && A.getOrientation() == East)
			{
				board[A.getAntRow()][A.getAntCol()] = '#';
				A.setOrientation(South);
				if (!A.setAntRow(++antRow, numberOfRows))
				{
					A.setAntRow(0, numberOfRows);
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				else
				{
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}

				board[A.getAntRow()][A.getAntCol()] = '*';
			}
			
			//space is white and orientation is south
			else if (A.getColor() == "white" && A.getOrientation() == South)
			{
				board[A.getAntRow()][A.getAntCol()] = '#';
				A.setOrientation(West);
				if (!A.setAntCol(--antCol, numberOfCols))
				{
					A.setAntCol(0, numberOfCols);
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				else
				{
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				board[A.getAntRow()][A.getAntCol()] = '*';
			}

			//space is white and orientation is west
			else if (A.getColor() == "white" && A.getOrientation() == West)
			{
				board[A.getAntRow()][A.getAntCol()] = '#';
				A.setOrientation(North);
				if (!A.setAntRow(--antRow, numberOfRows))
				{
					A.setAntRow(0, numberOfRows);
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				else
				{
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				board[A.getAntRow()][A.getAntCol()] = '*';
			}
			
			//space is black and orientation is north
			else if (A.getColor() == "black" && A.getOrientation() == North)
			{
				board[A.getAntRow()][A.getAntCol()] = ' ';
				A.setOrientation(West);
				if (!A.setAntCol(--antCol, numberOfCols))
				{
					A.setAntCol(0, numberOfCols);
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				else
				{
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				board[A.getAntRow()][A.getAntCol()] = '*';
			}

			//space is black and orientation is east
			else if (A.getColor() == "black" && A.getOrientation() == East)
			{
				board[A.getAntRow()][A.getAntCol()] = ' ';
				A.setOrientation(North);
				if (!A.setAntRow(--antRow, numberOfRows))
				{
					A.setAntRow(0, numberOfRows);
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				else
				{
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
			board[A.getAntRow()][A.getAntCol()] = '*';
			}

			//space is black and orientation is south
			else if (A.getColor() == "black" && A.getOrientation() == South)
			{
				board[A.getAntRow()][A.getAntCol()] = ' ';
				A.setOrientation(East);
				if (!A.setAntCol(++antCol, numberOfCols))
				{
					A.setAntCol(0, numberOfCols);
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				else
				{
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				board[A.getAntRow()][A.getAntCol()] = '*';
				}
			
			//if space is balck and orientation is west
			else
			{
				board[A.getAntRow()][A.getAntCol()] = ' ';
				A.setOrientation(South);
				if (!A.setAntRow(++antRow, numberOfRows))
				{
					A.setAntRow(0, numberOfRows);
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				else
				{
					if (board[A.getAntRow()][A.getAntCol()] == ' ')
					{
						A.setColor("white");
					}
					else if (board[A.getAntRow()][A.getAntCol()] == '#')
					{
						A.setColor("black");
					}
				}
				board[A.getAntRow()][A.getAntCol()] = '*';
			}

			//print board
			printBoard(board, numberOfRows, numberOfCols);
				std::cin.clear();
				std::cin.ignore();
				std::cin.get();
				
		}

		//deallocate memory
		for (int i = 0; i < numberOfRows; ++i)
		{
			delete[] board[i];
		}
		delete[] board;
	}
}

void printBoard(char** board, int numberOfRows, int numberOfCols)
{
	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfCols; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
		
	}

}

