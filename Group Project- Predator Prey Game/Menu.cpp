/*******************************************************************
 ** Program Name: Menu Class
 ** Author: Rebecca Vickers
 ** Date: 4/12/2018
 ** Description: This implementation file for the Menu class contains
 methods to build menus.  It has methods for two types of menus:
 a menu item that simply asks for user input and functions to build
 a multiple choice menu.  The methods call functions in the
 InputValidation class to validate user input.
 *******************************************************************/

#include "Menu.hpp"

/*******************************************************************
 promptForInteger function:
 This function accepts a string argument and returns an int.  It
 sets a prompt for the user and allows the user to input a response.
 It checks the user's response to ensure it is an integer.
 *******************************************************************/
int Menu::promptForInteger(std::string prompt)
{
    std::string response;
    std::cout << prompt << ": ";
    getline(std::cin,response);
    int convertedInt = validate.validateInt(response);
    
    return convertedInt;
}

/*******************************************************************
 getIntegerNoPrompt function:
 This function takes the next input from the user (without a prompt)
 and checks the user's response to ensure it is an integer.
 *******************************************************************/
int Menu::getIntegerNoPrompt()
{
    std::string response;
    getline(std::cin,response);
    int convertedInt = validate.validateInt(response);
    
    return convertedInt;
}

/*******************************************************************
 promptForIntegerWithRange function:
 This function accepts a string argument for the prompt and two int
 arguments for the minimum and maximum allowed values. It returns an
 int.  It sets a prompt for the user and allows the user to input a
 response. It checks the user's response to ensure it is an integer
 and that it is within the given range.
 *******************************************************************/
int Menu::promptForIntegerWithRange(std::string prompt, int minValue, int maxValue)
{
    std::string response;
    std::cout << prompt << ": ";
    getline(std::cin,response);
    int convertedInt = validate.validateInt(response);
    convertedInt = validate.validateRange(convertedInt, minValue, maxValue);
    
    return convertedInt;
}

/*******************************************************************
 promptForIntegerWithMin function:
 This function accepts a string argument for the prompt and an int
 argument for the minimum allowed value. It returns an int.  It sets
 a prompt for the user and allows the user to input a response. It
 checks the user's response to ensure it is an integer
 and that it is equal to or greater than the minimum value.
 *******************************************************************/
int Menu::promptForIntegerWithMin(std::string prompt, int minValue)
{
    std::string response;
    std::cout << prompt << ": ";
    getline(std::cin,response);
    int convertedInt = validate.validateInt(response);
    convertedInt = validate.validateRangeMinOnly(convertedInt, minValue);
    
    return convertedInt;
}

/*******************************************************************
 promptForIntegerWithMax function:
 This function accepts a string argument for the prompt and an int
 argument for the maximum allowed value. It returns an int.  It sets
 a prompt for the user and allows the user to input a response. It
 checks the user's response to ensure it is an integer
 and that it is equal to or greater than the maximum value.
 *******************************************************************/
int Menu::promptForIntegerWithMax(std::string prompt, int maxValue)
{
    std::string response;
    std::cout << prompt << ": ";
    getline(std::cin,response);
    int convertedInt = validate.validateInt(response);
    convertedInt = validate.validateRangeMaxOnly(convertedInt, maxValue);
    
    return convertedInt;
}

/*******************************************************************
 setPromptForChoicesMenu function:
 This function accepts a string argument.  It sets the prompt for a
 multiple choice menu using the argument.
 *******************************************************************/
void Menu::setPromptForChoicesMenu(std::string newPrompt)
{
    prompt = newPrompt;
}

/*******************************************************************
 addChoice function:
 This function accepts a string argument representing one of the
 multiple choice options.  It adds the string to a vector containing
 all of the multiple choice options.
 *******************************************************************/
void Menu::addChoice(std::string newChoice)
{
    choices.push_back(newChoice);
}

/*******************************************************************
 alterChoice function:
 This function accepts an int representing the location of the
 multiple choice item that will be altered and a string to replace
 the text of that option.  It changes the choice at that location to
 the new string.
 *******************************************************************/
void Menu::alterChoice(int choiceNumber, std::string changedOption)
{
    choices.at(choiceNumber - 1) = changedOption;
}

/*******************************************************************
 printChoicesMenu function:
 This ia a void function that accepts no arguments.  It prints the
 multiple choice menu prompt and all choices.
 *******************************************************************/
void Menu::printChoicesMenu()
{
    int choiceNumber = 1;
    
    std::cout << prompt << std::endl;
    for(int i = 0; i < static_cast<int>(choices.size()); i++)
    {
        std::cout << choiceNumber++ << ") ";
        std:: cout << choices.at(i) << std::endl;
    }
}

/*******************************************************************
 getUserSelection function:
 This function returns an int representing the user's choice and
 accepts no arguments.  It prompts the user to select a choice and
 checks to ensure the user selected a valid option.
 *******************************************************************/
int Menu::getUserSelection()
{
    int maxValue = static_cast<int>(choices.size());
    std::string response;
    std::cout << "Enter your choice here: ";
    getline(std::cin,response);
    int selection = validate.validateInt(response);
    selection = validate.validateRange(selection, 1, maxValue);
    
    return selection;
}
