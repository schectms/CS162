/*******************************************************************************
 ** Author: Group 39
 ** Date: 5/11/2018
 ** Description: Board class declaration
*******************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

class Board{
private:
    int numberOfRows;
    int numberOfColumns;
    int numberOfAnts;
    int numberOfDoodlebugs;
    Critter ***critterBoard;
public:
    Board(int numberOfRows, int numberOfColumns);
    ~Board();
    int getNumberOfAnts();
    int getNumberOfDoodlebugs();
    int getNumberOfRows();
    int getNumberOfColumns();
    Critter* getSpace(int rowNumber, int columnNumber);
    void setNumberOfRows(int numberOfRows);
    void setNumberOfColumns(int numberOfColumns);
    void setSpace(int rowNumber, int columnNumber, Critter* newCritter);
    void setNumberOfAnts();
    void setNumberOfDoodlebugs();
    void displayBoard();
    void moveCritters();
    void breedCritters();
    void fillBoard(int numberOfAnts, int numberOfDoodlebugs);
    void resetTimeStepDone();
};

#endif
