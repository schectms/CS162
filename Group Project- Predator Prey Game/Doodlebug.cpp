/*******************************************************************************
 ** Author: Group 39
 ** Date: 5/11/2018
 ** Description: Doodlebug class implementation- derived class
*******************************************************************************/

#include "Doodlebug.hpp"

/*******************************************************************************
  Func: Doodlebug(int currentRow, int currentCol)
  Desc: Contructor initializes data members of object using Critter constructor
        critterType is also set
  Params: int currentRow - represents the row position on board
          int currentColumn - represents the column position on board
*******************************************************************************/
Doodlebug::Doodlebug(int currentRow, int currentCol) :Critter(currentRow, currentCol){
    critterType = 'X';
}

/*******************************************************************************
  Func: ~Doodlebug()
  Desc: Virtual destructor
*******************************************************************************/
Doodlebug::~Doodlebug(){}


/*******************************************************************************
  Func: bool move(Board &board)
  Desc: Returns a boolean value representing whether the doodlebug was able to 
        move or not. There are 3 possible scenarios:
            1: there is an ant in an adjacent cell - in this case, the 
                    ant is eaten and a replica of this doodlebug is 
                    created in its place
            2: there is no adjacent ant but there is an adjacent empty space - 
                    a replica of this doodlebug is created in a adjacent empty
                      space
            3:  no adjacent ants and empty space - doodlebug does not move
        For each of these scenarios, the doodlebug starves if it hasn't eaten
        in 3 time steps. The calling doodlebug later gets deleted.
  Params: Board& - this should be the address of the board 
                   containing the doodlebug
*******************************************************************************/
bool Doodlebug::move(Board &board){
    std::vector<int> possibleMoves = getAdjacentEmptySpaces(board);
    //Scenario: there is an doodlebug in an adjacent cell
    if (canEat(board)) {
        int doodlebugAdjacent = canEat(board);
        if (doodlebugAdjacent != 0) {
            switch (static_cast<Direction>(doodlebugAdjacent)) {
                case UP:
                {
                    //delete ant
                    delete board.getSpace(currentRow - 1, currentCol);
                    board.setSpace(currentRow - 1, currentCol, nullptr);
                    
                    //replace doodlebug with replica of this doodlebug
                    copyCritter(board, currentRow - 1, currentCol);
                    board.getSpace(currentRow - 1, currentCol)->setEatenStepCount(0);
                    return true;
                    break;
                }
                    
                case RIGHT:
                {
                    delete board.getSpace(currentRow, currentCol + 1);
                    board.setSpace(currentRow, currentCol + 1, nullptr);
                    copyCritter(board, currentRow, currentCol + 1);
                    board.getSpace(currentRow, currentCol + 1)->setEatenStepCount(0);
                    return true;
                    break;
                }
                    
                case DOWN:
                {
                    delete board.getSpace(currentRow + 1, currentCol);
                    board.setSpace(currentRow + 1, currentCol, nullptr);
                    copyCritter(board, currentRow + 1, currentCol);
                    board.getSpace(currentRow + 1, currentCol)->setEatenStepCount(0);
                    return true;
                    break;
                }
                    
                case LEFT:
                {
                    delete board.getSpace(currentRow, currentCol - 1);
                    board.setSpace(currentRow, currentCol - 1, nullptr);
                    copyCritter(board, currentRow, currentCol - 1);
                    board.getSpace(currentRow, currentCol - 1)->setEatenStepCount(0);
                    return true;
                    break;
                }
            }
        }
    }

    //Scenario: there is no doodlebug in any adjacent cell but there is an empty cell
    else if (possibleMoves.size() != 0) {
        switch (static_cast<Direction>(possibleMoves.at(rand() % possibleMoves.size()))) {
            case UP:
            {
                //create replica of this doodle bug in adjacent cell
                copyCritter(board, currentRow - 1, currentCol);
                board.getSpace(currentRow - 1, currentCol)->setEatenStepCount(getEatenStepCount() + 1);

                //if doodlebug hasn't eaten in 3 time steps, it starves
                if ((board.getSpace(currentRow - 1, currentCol)->getEatenStepCount()) == 3) {
                    delete board.getSpace(currentRow - 1, currentCol);
                    board.setSpace(currentRow - 1, currentCol, nullptr);
                }
                break;
            }
                
            case RIGHT:
            {
                copyCritter(board, currentRow, currentCol + 1);
                board.getSpace(currentRow, currentCol + 1)->setEatenStepCount(getEatenStepCount() + 1);
                if ((board.getSpace(currentRow, currentCol + 1)->getEatenStepCount()) == 3) {
                    delete board.getSpace(currentRow, currentCol + 1);
                    board.setSpace(currentRow, currentCol + 1, nullptr);
                }
                break;
            }
                
            case DOWN:
            {
                copyCritter(board, currentRow + 1, currentCol);
                board.getSpace(currentRow + 1, currentCol)->setEatenStepCount(getEatenStepCount() + 1);
                if ((board.getSpace(currentRow + 1, currentCol)->getEatenStepCount()) == 3) {
                    delete board.getSpace(currentRow + 1, currentCol);
                    board.setSpace(currentRow + 1, currentCol, nullptr);
                }
                break;
            }
                
            case LEFT:
            {
                copyCritter(board, currentRow, currentCol - 1);
                board.getSpace(currentRow, currentCol - 1)->setEatenStepCount(getEatenStepCount() + 1);
                if ((board.getSpace(currentRow, currentCol - 1)->getEatenStepCount()) == 3) {
                    delete board.getSpace(currentRow, currentCol - 1);
                    board.setSpace(currentRow, currentCol - 1, nullptr);
                }
                break;
            }
        }
    }

    //Scenario: no ants and no empty space in adjacent cells
    else {
        //increase time step counts
        setBreedStepCount(getBreedStepCount() + 1);
        setEatenStepCount(getEatenStepCount() + 1);
        if (getEatenStepCount() != 3) {
            return false;
        }
        //else starve: doodlebug will be deleted by board class
    }
    return true;
}


/*******************************************************************************
  Func: bool canBreed()
  Desc: Returns a boolean value representimg whether the doodlebug can breed or not. 
        A doodlebug can breed when it reaches 8 time steps
*******************************************************************************/

bool Doodlebug::canBreed(){
    if (getBreedStepCount() >= 8){
        return true;
    }
    else{
        return false;
    }
}

/*******************************************************************************
  Func: void breed(Board &board)
  Desc: This function randomly picks an adjacent empty space (from available
        empty spaces) and creates a new doodlebug in that space. It then resets 
      the breed count so the doodlebug can not breed for another 8 steps. If 
        no empty space is available or the doodlebug hasn't survived long 
        enough, the function does nothing
  Params: Board& - this should be the address of the board 
                   containing the ant
*******************************************************************************/

void Doodlebug::breed(Board &board) {
    if(canBreed()){
        std::vector<int> possibleMoves = getAdjacentEmptySpaces(board);
        if (possibleMoves.size() != 0) {
            switch (static_cast<Direction>(possibleMoves.at(rand() % possibleMoves.size()))) {
                case UP:
                {
                    board.setSpace(currentRow - 1, currentCol, new Doodlebug(currentRow - 1, currentCol));
                    board.getSpace(currentRow, currentCol)->setBreedStepCount(0);
                    break;
                }
                    
                case RIGHT:
                {
                    board.setSpace(currentRow, currentCol + 1, new Doodlebug(currentRow, currentCol + 1));
                    board.getSpace(currentRow, currentCol)->setBreedStepCount(0);
                    break;
                }
                    
                case DOWN:
                {
                    board.setSpace(currentRow + 1, currentCol, new Doodlebug(currentRow + 1, currentCol));
                    board.getSpace(currentRow, currentCol)->setBreedStepCount(0);
                    break;
                }
                    
                case LEFT:
                {
                    board.setSpace(currentRow, currentCol - 1, new Doodlebug(currentRow, currentCol - 1));
                    board.getSpace(currentRow, currentCol)->setBreedStepCount(0);
                    break;
                }
            }
        }
    }
}

/*******************************************************************************
  Func: void copyCritter(Board &board, int currentRow, int currentColumn)
  Desc: Creates replica doodlebug calling in the specified space on the board;
        The data members for the new doodlebug are set to match the calling doodlebug
  Params: Board& - this should be the address of the board 
                   containing the ant
          int currentRow - row position of new space on board
          int currentColumn - column position of new space on board
*******************************************************************************/

void Doodlebug::copyCritter(Board &board, int currentRow, int currentColumn){
    board.setSpace(currentRow, currentColumn, new Doodlebug(currentRow, currentColumn));
    board.getSpace(currentRow, currentColumn)->setBreedStepCount(getBreedStepCount() + 1);
    board.getSpace(currentRow, currentColumn)->setTimeStepDone(getTimeStepDone()); 
}

