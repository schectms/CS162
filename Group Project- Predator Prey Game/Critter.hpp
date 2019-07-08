/*******************************************************************************
 ** Author: Group 39
 ** Date: 5/11/2018
 ** Description: Critter class declaration - base class
*******************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <cstdlib>
#include <vector>

class Board;
enum Direction{UP=1, RIGHT, DOWN, LEFT};

class Critter{
protected:
    int currentRow;
    int currentCol;
    bool timeStepDone;
    char critterType;
    int breedStepCount;
    int eatenStepCount;

public:
    Critter(int currentRow, int currentColumn);
    virtual ~Critter();
    char getCritterType();
    bool getTimeStepDone();
    int getBreedStepCount();
    int getEatenStepCount();
    void setTimeStepDone(bool timeStepDone);
    void setBreedStepCount(int breedStepCount);
    void setEatenStepCount(int eatenStepCount);
    std::vector<int> getAdjacentEmptySpaces(Board &board);
    int canEat(Board &board);
    virtual void breed(Board &board);
    virtual bool move(Board &board);
    virtual bool canBreed();
    virtual void copyCritter(Board &board, int currentRow, int currentColumn);
};

#endif

