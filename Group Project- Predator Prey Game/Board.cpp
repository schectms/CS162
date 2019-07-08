/*******************************************************************************
 ** Author: Group 39
 ** Date: 5/11/2018
 ** Description: Board class implementation
*******************************************************************************/

#include "Board.hpp"

/*******************************************************************************
  Func: Board(int numberOfRows, int numberOfColumns
  Desc: Contructor initializes a board of size numberOfRows X numberOfColumns
        Each space on the board is a pointer to a Critter. Each pointer is set
        to null when the constructor is called.
  Params: int currentRow - represents the # of rows on board
          int currentColumn - represents the # of columns on board
*******************************************************************************/
Board::Board(int numberOfRows, int numberOfColumns){
    this->numberOfRows = numberOfRows;
    this->numberOfColumns = numberOfColumns;
    numberOfAnts = 0;
    numberOfDoodlebugs = 0;
    critterBoard = new Critter**[numberOfRows];
    for(int i = 0; i < numberOfRows; ++i){
        critterBoard[i] = new Critter*[numberOfColumns];
    }
    
    for(int i = 0; i < numberOfRows; i++){
        for(int j = 0; j < numberOfColumns; j++){
            critterBoard[i][j] = nullptr;
        }
    }
}


/*******************************************************************************
  Func: ~Board()
  Desc: Destructor deletes all of the pointer to critters
*******************************************************************************/
Board::~Board(){
    for(int i = 0; i < numberOfRows; ++i) {
        if(critterBoard[i] != nullptr){
            for(int j = 0; j < numberOfColumns; j++){
                if(critterBoard[i][j] != nullptr){
                    delete critterBoard[i][j];
                }
            }
            delete [] critterBoard[i];
        }
    }
    if(critterBoard != nullptr){
        delete [] critterBoard;
    }
}


/*******************************************************************************
  Func: int getNumberOfAnts()
  Desc: Returns the integer value of the number of ants on board
*******************************************************************************/
int Board::getNumberOfAnts(){
    return numberOfAnts;
}

/*******************************************************************************
  Func: int getNumberOfDoodlebugs()
  Desc: Returns the integer value of the number of doodlebugs on board
*******************************************************************************/
int Board::getNumberOfDoodlebugs(){
    return numberOfDoodlebugs;
}

/*******************************************************************************
  Func: int getNumberOfRows()
  Desc: Returns the integer value of the number of rows on board
*******************************************************************************/
int Board::getNumberOfRows(){
    return numberOfRows;
}

/*******************************************************************************
  Func: int getNumberOfColumns()
  Desc: Returns the integer value of the number of columns on board
*******************************************************************************/
int Board::getNumberOfColumns(){
    return numberOfColumns;
}

/*******************************************************************************
  Func: void Board::setNumberOfRows(int numberOfRows)
  Desc: Sets the numberOfRows data member to argument specified by parameter
  Params: int numberOfRows - represents number of board rows
*******************************************************************************/
void Board::setNumberOfRows(int numberOfRows){
    this->numberOfRows = numberOfRows;
}

/*******************************************************************************
  Func: void Board::setNumberOfColumns(int numberOfColumns)
  Desc: Sets the numberOfColumns data member to argument specified by parameter
  Params: int numberOfColumns - represents number of board columns
*******************************************************************************/
void Board::setNumberOfColumns(int numberOfColumns){
    this->numberOfColumns = numberOfColumns;
}

/*******************************************************************************
  Func: void fillBoard(int numberOfAnts, int numberOfDoodlebugs)
  Desc: Fills the board with the specified number of ants and doodlebugs
  Params: int numberOfAnts - # of ants to place on board
          int numberOfDoodlebugs - # of doodlebugs to place on board
*******************************************************************************/
void Board::fillBoard(int numberOfAnts, int numberOfDoodlebugs){
    //add doodlebugs to board
    for(int i = 0; i < numberOfDoodlebugs; i++){
        int rowNumber = rand() % numberOfRows;
        int columnNumber = rand() % numberOfColumns;
        bool spaceAvailable = (critterBoard[rowNumber][columnNumber] == nullptr);
        while(!spaceAvailable){
            rowNumber = rand() % numberOfRows;
            columnNumber = rand() % numberOfColumns;
            spaceAvailable = (critterBoard[rowNumber][columnNumber] == nullptr);
        }
        critterBoard[rowNumber][columnNumber] = new Doodlebug(rowNumber, columnNumber);
    }

    //add ants to board
    for(int i = 0; i < numberOfAnts; i++){
        int rowNumber = rand() % numberOfRows;
        int columnNumber = rand() % numberOfColumns;
        bool spaceAvailable = (critterBoard[rowNumber][columnNumber] == nullptr);
        while(!spaceAvailable){
            rowNumber = rand() % numberOfRows;
            columnNumber = rand() % numberOfColumns;
            spaceAvailable = (critterBoard[rowNumber][columnNumber] == nullptr);
        }
        critterBoard[rowNumber][columnNumber] = new Ant(rowNumber, columnNumber);
        }

    //update number of ants and doodlebugs on board
    setNumberOfDoodlebugs();
    setNumberOfAnts();
}

/*******************************************************************************
  Func: void displayBoard()
  Desc: Loops through all of the pointers and prints the character type for any
        critter on the board. Displays in a grid format
*******************************************************************************/

void Board::displayBoard(){
    if(critterBoard != nullptr){
        for(int i = 0; i < numberOfRows; i++){
            std::cout << std::endl << '|';;
            for(int j = 0; j < numberOfColumns; j++){
                if(critterBoard[i][j] == nullptr){
                    std::cout << ' ';
                }
                else{
                    std::cout << critterBoard[i][j]->getCritterType();
                }
                std::cout << '|';
            }
        }
        std::cout << std::endl << std::endl;
    }
}

/*******************************************************************************
  Func: Critter* getSpace(int rowNumber, int columnNumber)
  Desc: Returns the pointer to Critter at the position on the board specified
        by the parameters
  Params: int rowNumber - represents the row position on board
          int columnNumber - represents the column position on board
*******************************************************************************/
Critter* Board::getSpace(int rowNumber, int columnNumber){
    if(critterBoard[rowNumber][columnNumber] != nullptr){
        return critterBoard[rowNumber][columnNumber];
    }
    return nullptr;
}

/*******************************************************************************
  Func: void setSpace(int rowNumber, int columnNumber, Critter* newCritter)
  Desc: Assigns the Critter* at the position on the board specified by the first
        2 parameters to the Critter* specified by the 3rd parameter
  Params: int rowNumber - represents the row position on board
          int columnNumber - represents the column position on board
          Critter* newCritter - Critter* that Critter* at the board position
                                will now point to
*******************************************************************************/
void Board::setSpace(int rowNumber, int columnNumber, Critter* newCritter){
    critterBoard[rowNumber][columnNumber] = newCritter;
}

/*******************************************************************************
  Func: void Board::breedCritters()
  Desc: Loops through all pointers to critters in the board and calls their
        breed function. It then updates the number of ants and doodlebugs on the
        board
*******************************************************************************/
void Board::breedCritters(){
    for(int i = 0; i < numberOfRows; ++i) {
        for(int j = 0; j < numberOfColumns; j++){
            if(critterBoard[i][j] != nullptr){
                critterBoard[i][j]->breed(*this);
            }
        }
    }
setNumberOfDoodlebugs();
setNumberOfAnts();
}

/*******************************************************************************
  Func: void Board::moveCritters()
  Desc: Loops through all pointers to critters in the board and calls their
        move function. After each move, the Critter's timeStepDone member is set
        to true to avoid moving the critter multiple times in one time step.
        It then updates the number of ants and doodlebugs on the
        board. The doodlebugs always move before the ants. 
*******************************************************************************/
void Board::moveCritters(){
    //move doodlebugs
    for(int i = 0; i < numberOfRows; ++i) {
        for(int j = 0; j < numberOfColumns; j++){
            if(critterBoard[i][j] != nullptr && (!critterBoard[i][j]->getTimeStepDone())){
                if(critterBoard[i][j]->getCritterType() == 'X'){
                    critterBoard[i][j]->setTimeStepDone(true);
                    bool movedSuccessfully;
                    movedSuccessfully = (critterBoard[i][j]->move(*this));
                    if(movedSuccessfully){
                        delete critterBoard[i][j];
                        critterBoard[i][j] = nullptr;
                    }
                }
            }
        }
    }

    //move ants
    for(int i = 0; i < numberOfRows; ++i) {
        for(int j = 0; j < numberOfColumns; j++){
            if(critterBoard[i][j] != nullptr && (!critterBoard[i][j]->getTimeStepDone())){
                if(critterBoard[i][j]->getCritterType() == 'O'){
                    critterBoard[i][j]->setTimeStepDone(true);
                    bool movedSuccessfully;
                    movedSuccessfully = (critterBoard[i][j]->move(*this));
                    if(movedSuccessfully){
                        delete critterBoard[i][j];
                        critterBoard[i][j] = nullptr;
                    }
                }
            }
        }
    }

    //update number of ants and doodlebugs on board
    setNumberOfDoodlebugs();
    setNumberOfAnts();
}



/*******************************************************************************
  Func: void Board::resetTimeStepDone()
  Desc: resets the timeStepDone data member of each critter (sets it to false).
*******************************************************************************/
void Board::resetTimeStepDone(){
    for(int i = 0; i < numberOfRows; ++i) {
        for(int j = 0; j < numberOfColumns; j++){
            if(critterBoard[i][j] != nullptr){
                critterBoard[i][j]->setTimeStepDone(false);
            }
        }
    }
}


/*******************************************************************************
  Func: void setNumberOfAnts()
  Desc: updates the numberOfAnts data member with the number of ants currently
        on the board by looping through the board and incrementing the count
        whenever an ant is encountered. The critterType character is used to 
        test which kind of critter each Critter* points to.
*******************************************************************************/
void Board::setNumberOfAnts(){
    numberOfAnts = 0;
    for(int i = 0; i < numberOfRows; ++i) {
        for(int j = 0; j < numberOfColumns; j++){
            if(critterBoard[i][j] != nullptr){
                if(critterBoard[i][j]->getCritterType() == 'O'){
                    numberOfAnts++;
                }
            }
        }
    }
}


/*******************************************************************************
  Func: void setNumberOfDoodlebugs
  Desc: updates the numberOfDoodlebugs data member with the number of doodlebugs
        on the board by looping through the board and incrementing the count
        whenever a doodlebug is encountered. The critterType character is used to 
        test which kind of critter each Critter* points to.
*******************************************************************************/
void Board::setNumberOfDoodlebugs(){
    numberOfDoodlebugs = 0;
    for(int i = 0; i < numberOfRows; ++i) {
        for(int j = 0; j < numberOfColumns; j++){
            if(critterBoard[i][j] != nullptr){
                if(critterBoard[i][j]->getCritterType() == 'X'){
                    numberOfDoodlebugs++;
                }
            }
        }
    }
}



