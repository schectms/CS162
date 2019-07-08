/*******************************************************************************
 ** Author: Group 39
 ** Date: 5/11/2018
 ** Description: Ant class implementation - derived class
*******************************************************************************/

#include "Ant.hpp"

/*******************************************************************************
  Func: Ant(int currentRow, int currentCol)
  Desc: Contructor initializes data members of object using Critter constructor
        critterType is also set
  Params: int currentRow - represents the row position on board
          int currentColumn - represents the column position on board
*******************************************************************************/

Ant::Ant(int currentRow, int currentCol) :Critter(currentRow, currentCol){
    critterType = 'O';
}

/*******************************************************************************
  Func: ~Ant()
  Desc: Virtual destructor
*******************************************************************************/
Ant::~Ant(){}

/*******************************************************************************
  Func: void breed(Board &board)
  Desc: This function randomly picks an adjacent empty space (from available
        empty spaces) and creates a new ant in that space. It then resets the 
        breed count so the ant can not breed for another 3 steps. If no empty
        space is available or the ant hasn't survived long enough, the function
        does nothing
  Params: Board& - this should be the address of the board 
                   containing the ant
*******************************************************************************/

void Ant::breed(Board &board) {
    if(this->canBreed()){
        std::vector<int> possibleMoves = getAdjacentEmptySpaces(board);
        if (possibleMoves.size() != 0) {
            switch (static_cast<Direction>(possibleMoves.at(rand() % possibleMoves.size()))) {
                case UP:
                {
                    board.setSpace(currentRow - 1, currentCol, new Ant(currentRow - 1, currentCol));
                    board.getSpace(currentRow, currentCol)->setBreedStepCount(0);
                    break;
                }
                    
                case RIGHT:
                {
                    board.setSpace(currentRow, currentCol + 1, new Ant(currentRow, currentCol + 1));
                    board.getSpace(currentRow, currentCol)->setBreedStepCount(0);
                    break;
                }
                    
                case DOWN:
                {
                    board.setSpace(currentRow + 1, currentCol, new Ant(currentRow + 1, currentCol));
                    board.getSpace(currentRow, currentCol)->setBreedStepCount(0);
                    break;
                }
                    
                case LEFT:
                {
                    board.setSpace(currentRow, currentCol - 1, new Ant(currentRow, currentCol - 1));
                    board.getSpace(currentRow, currentCol)->setBreedStepCount(0);
                    break;
                }
            }
        }
    }
}

/*******************************************************************************
  Func: bool move(Board &board)
  Desc: Returns a boolean value representing whether the ant was able to move or
        not. Moving consists of randomly picking an adjacent empty space (from 
        available empty spaces) and creates a replica ant in that space. 
        The calling ant later gets deleted.
  Params: Board& - this should be the address of the board 
                   containing the ant
*******************************************************************************/

bool Ant::move(Board &board) {
    std::vector<int> possibleMoves = getAdjacentEmptySpaces(board);
    if (possibleMoves.size() != 0) {
        switch (static_cast<Direction>(possibleMoves.at(rand() % possibleMoves.size()))) {
            case UP:
            {
                copyCritter(board, currentRow - 1, currentCol);
                return true;
                break;
            }
                
            case RIGHT:
            {
                copyCritter(board, currentRow, currentCol + 1);
                return true;
                break;
            }
                
            case DOWN:
            {
                copyCritter(board, currentRow + 1, currentCol);
                return true;
                break;
            }
                
            case LEFT:
            {
                copyCritter(board, currentRow, currentCol - 1);
                return true;
                break;
            }
        }
    }
    return false;
}

/*******************************************************************************
  Func: bool canBreed()
  Desc: Returns a boolean value representimg whether the ant can breed or not. 
        An ant can breed when it reaches 3 time steps
*******************************************************************************/

bool Ant::canBreed(){
    if (getBreedStepCount() >= 3){
        return true;
    }
    else{
        return false;
    }
}

/*******************************************************************************
  Func: void copyCritter(Board &board, int currentRow, int currentColumn)
  Desc: Creates replica ant calling in the specified space on the board;
        The data members for the new ant are set to match the calling ant
  Params: Board& - this should be the address of the board 
                   containing the ant
          int currentRow - row position of new space on board
          int currentColumn - column position of new space on board
*******************************************************************************/

void Ant::copyCritter(Board &board, int currentRow, int currentColumn){
    board.setSpace(currentRow, currentColumn, new Ant(currentRow, currentColumn));
    board.getSpace(currentRow, currentColumn)->setBreedStepCount(getBreedStepCount() + 1);
    board.getSpace(currentRow, currentColumn)->setTimeStepDone(getTimeStepDone()); 
}

