/*******************************************************************
 ** Program Name: Predator-Prey Game
 ** Author: Group 39
 ** Date: 5/10/2018
 ** Description: Simulates a predator-prey game.  Has menus to prompt
 the user for data needed to run the game.  Continues running the
 simulation for the number of time steps specified by the user.
 Allows the user to continue game simulation for additional time
 steps or quit.
 *******************************************************************/

#include "Menu.hpp"
#include "Board.hpp"

int main(){
    Menu promptForData;         //Menu to prompt user for data needed to
                                //create and fill the board.
    Menu continuePlayingMenu;   //Menu to prompt user to continue for
                                //more time steps or quit.
    
    int numSteps;               //Number of time steps
    int numRows;                //Number of rows in grid
    int numCols;                //Number of columns in grid
    int numAnts;                //Number of ants to begin with
    int numDoodlebugs;          //Number of doodlebugs to begin with
    int playMore;               //User choice to play more or quit
    int totalSteps = 0;         //Accumulated number of steps for when
                                //user chooses to continue playing.
    
    
    std::cout << "************ PREDATOR-PREY GAME ************" << std::endl;
    std::cout << "\n";
    std::cout << "*Extra Credit*" << std:: endl;
    std::cout << "\n";
    
    //Display prompts for user to input data necessary for creating and
    //filling the board.
    numSteps = promptForData.promptForIntegerWithMin
        ("For how many time steps should your Predator-Prey Game run?", 1);
    numRows = promptForData.promptForIntegerWithMin
        ("How many rows should be in your grid?", 1);
    numCols = promptForData.promptForIntegerWithMin
        ("How many columns should be in your grid?", 1);
    Board gameBoard(numRows, numCols);

    //Make sure the number of ants and doodlebugs enter can fit on the board
    do{
        numAnts = promptForData.promptForIntegerWithMin
            ("How many ants should your game begin with?", 1);
        numDoodlebugs = promptForData.promptForIntegerWithMin
            ("How many doodlebugs should your game begin with?", 1);
        
        if(numAnts + numDoodlebugs > numRows * numCols){
            std::cout << "\nThe number of ants and doodlebugs must not exceed "
                      << "the board spaces\n";
        }
    }
    while((numAnts + numDoodlebugs) > (numRows * numCols));

        gameBoard.fillBoard(numAnts, numDoodlebugs);

    //Set up menu for user to choose to continue playing or quit.
    continuePlayingMenu.setPromptForChoicesMenu
        ("Would you like to continue playing for more time steps or quit?");
    continuePlayingMenu.addChoice("Keep playing!");
    continuePlayingMenu.addChoice("Quit");
    std::cout << "\n";

    std::cout << "INITIAL BOARD" << std::endl;
    gameBoard.displayBoard();       //Show the resulting board
    
    //While user chooses to continue playing, loop through simulation
    //for number of time steps specified by user.
    do
    {
        //Loop for number of time steps indicated by user
        for(int i = 0; i < numSteps; i++)
        {
            gameBoard.resetTimeStepDone();  //Reset time step indicator
                                            //for all critters
            gameBoard.moveCritters();       //All critters move
            gameBoard.breedCritters();      //All eligible critters breed
            
            std::cout << "TIME STEP #" << ++totalSteps << std::endl;
            gameBoard.displayBoard();       //Show the resulting board
        }
        
        //Give user option to play additional time steps or quit.
        continuePlayingMenu.printChoicesMenu();
        playMore = continuePlayingMenu.getUserSelection();
        std::cout << "\n";
        
        if(playMore == 1)
        {
            numSteps = promptForData.promptForIntegerWithMin
                ("How many more time steps would you like to play?", 1);
            std::cout << "\n";
        }
    }
    while(playMore == 1);
    
    return 0;
}
