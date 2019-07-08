/*******************************************************************
 ** Program Name: Menu Class
 ** Author: Rebecca Vickers
 ** Date: 4/12/2018
 ** Description: This declaration file for the Menu class declares
 methods to build menus.  It has methods for two types of menus:
 a menu item that simply asks for user input and functions to build
 a multiple choice menu.  The methods call functions in the
 InputValidation class to validate user input.
 *******************************************************************/

#ifndef Menu_hpp
#define Menu_hpp
#include <vector>
#include "InputValidation.hpp"

class Menu
{
private:
    InputValidation validate;
    std::string prompt;
    std::vector<std::string> choices;
public:
    int promptForInteger(std::string prompt);
    int getIntegerNoPrompt();
    int promptForIntegerWithRange(std::string prompt, int minValue, int maxValue);
    int promptForIntegerWithMin(std::string prompt, int minValue);
    int promptForIntegerWithMax(std::string prompt, int maxValue);
    void setPromptForChoicesMenu(std::string newPrompt);
    void addChoice(std::string newChoice);
    void alterChoice(int choiceNumber, std::string changedOption);
    void printChoicesMenu();
    int getUserSelection();
};

#endif /* Menu_hpp */


