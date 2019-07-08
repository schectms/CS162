/*******************************************************************************
 ** Author: Group 39
 ** Date: 5/11/2018
 ** Description: Critter class implementation - base class
*******************************************************************************/
#include "Critter.hpp"
#include "Board.hpp"


/*******************************************************************************
  Func: Critter::Critter(int currentRow, int currentColumn)
  Desc: Contructor initializes data members of object
  Params: int currentRow - represents the row position on board
//        int currentColumn - represents the column position on board
*******************************************************************************/

Critter::Critter(int currentRow, int currentColumn){
    breedStepCount = 0;
    eatenStepCount = 0;
    timeStepDone = 0;
    this->currentRow = currentRow;
    this->currentCol = currentColumn;
}

/*******************************************************************************
  Func: ~Critter()
  Desc: Virtual destructor ensures derived classes are destroyed
//      using their own destructor
*******************************************************************************/
Critter::~Critter(){}

/*******************************************************************************
  Func: getter functions
  Desc: Returns the value of the specified data member
*******************************************************************************/
char Critter::getCritterType(){
    return critterType;
}

bool Critter::getTimeStepDone(){
    return timeStepDone;
}

int Critter::getBreedStepCount(){
    return breedStepCount;
}

int Critter::getEatenStepCount(){
    return eatenStepCount;
}

/*******************************************************************************
  Func: setter functions
  Desc: Sets the value of the data member specified to the argument provided
*******************************************************************************/
void Critter::setTimeStepDone(bool timeStepDone){
    this->timeStepDone = timeStepDone;
}

void Critter::setBreedStepCount(int breedStepCount){
    this->breedStepCount = breedStepCount;
}

void Critter::setEatenStepCount(int eatenStepCount){
    this->eatenStepCount = eatenStepCount;
}


/*******************************************************************************
  Func: std::vector<int> getAdjacentEmptySpaces(Board &board)
  Desc: Returns an integer vector containing all of the directions
        for which adjacent cells are empty
  Params: Board& - this should be the address of the board 
                   containing the critter
*******************************************************************************/

std::vector<int> Critter::getAdjacentEmptySpaces(Board &board){
    std::vector<int> possibleMoves;

    //check if space 1 UP is empty
    if(currentRow - 1 > 0){
        if(board.getSpace(currentRow-1, currentCol) == nullptr){
            possibleMoves.push_back(1);
        }
    }

    //check if space 1 RIGHT is empty
    if(currentCol + 1 < board.getNumberOfColumns()){
        if(board.getSpace(currentRow, currentCol+1) == nullptr){
            possibleMoves.push_back(2);
        }
    }

    //check if space 1 DOWN is empty
    if(currentRow + 1 < board.getNumberOfRows()){
        if(board.getSpace(currentRow+1, currentCol) == nullptr){
            possibleMoves.push_back(3);
        }
    }

    //check if space 1 LEFT is empty
    if(currentCol - 1 > 0){
        if(board.getSpace(currentRow, currentCol-1) == nullptr){
            possibleMoves.push_back(4);
        }
    }
    return possibleMoves;
}

/*******************************************************************************
  Func: int canEat(Board &board)
  Desc: returns an integer value representing the direction of the first adjacent
//      cell containing an ant
  Params: Board& - this should be the address of the board 
//        containing the critter
*******************************************************************************/

int Critter::canEat(Board &board){
    
    if(currentRow - 1 > 0){
        if(board.getSpace(currentRow-1, currentCol) != nullptr){
            if(board.getSpace(currentRow-1, currentCol)->getCritterType() == 'O'){
                return 1;
            }
        }
    }
    
    if(currentCol + 1 < board.getNumberOfColumns()){
        if(board.getSpace(currentRow, currentCol+1) != nullptr){
            if(board.getSpace(currentRow, currentCol+1)->getCritterType() == 'O'){
                return 2;
            }
        }
    }
    
    if(currentRow + 1 < board.getNumberOfRows()){
        if(board.getSpace(currentRow+1, currentCol) != nullptr){
            if(board.getSpace(currentRow+1, currentCol)->getCritterType() == 'O'){
                return 3;
            }
        }
    }
    
    if(currentCol - 1 > 0){
        if(board.getSpace(currentRow, currentCol-1) != nullptr){
            if(board.getSpace(currentRow, currentCol-1)->getCritterType() == 'O'){
                return 4;
            }
        }
    }
    
    return 0;
}

/*******************************************************************************
VIRTUAL FUNCTIONS - in depth descriptions in derived classes
*******************************************************************************/
bool Critter::move(Board &board) {return 0;}
void Critter::breed(Board &board){}
bool Critter::canBreed() {return 0;}
void Critter::copyCritter(Board &board, int currentRow, int currentColumn){}

