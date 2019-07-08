/*******************************************************************
 ** Program Name: InputValidation Class
 ** Author: Rebecca Vickers
 ** Date: 4/12/2018
 ** Description: This implementation file for the InputValidation
 class contains methods to validate if an input is an integer,
 validate if it is within a certian range, or greater than a min value,
 or greater than a max value.  Function design informed by:
 http://www.cplusplus.com/forum/articles/6046/
 *******************************************************************/

#include "InputValidation.hpp"

/*******************************************************************
 validateInt function:
 This function accepts a string argument and returns an int.  It
 uses stringstream to validate if an input string can be converted
 to an int.
 *******************************************************************/
int InputValidation::validateInt(std::string input)
{
    int stringToInt;
    
    while(true)
    {
        std::stringstream inputStream(input);
        
        if(inputStream >> stringToInt)
        {
            return stringToInt;
        }
        else
        {
            std::cout << "Invalid entry. Please try again: ";
            getline(std::cin,input);
        }
    }
    
    return stringToInt;
}

/*******************************************************************
 validateRange function:
 This function accepts 3 int arguments representing an input value
 and minimum and maximum allowed values.  It returns an int.  It
 verifies if the supplied input is within a given range.
 *******************************************************************/
int InputValidation::validateRange(int input, int minValue, int maxValue)
{
    while(true)
    {
        if(input >= minValue && input <= maxValue)
        {
            return input;
        }
        else
        {
            std::cout << "Invalid entry. Please try again: ";
            std::string newInput;
            getline(std::cin,newInput);
            input = validateInt(newInput);
        }
    }
    return input;
}

/*******************************************************************
 validateRangeMinOnly function:
 This function accepts 2 int arguments representing an input value
 and minimum allowed value.  It returns an int.  It verifies if the
 supplied input is greater than or equal to the allowed minimum value.
 *******************************************************************/
int InputValidation::validateRangeMinOnly(int input, int minValue)
{
    while(true)
    {
        if(input >= minValue)
        {
            return input;
        }
        else
        {
            std::cout << "Invalid entry. Please try again: ";
            std::string newInput;
            getline(std::cin,newInput);
            input = validateInt(newInput);
        }
    }
    return input;
}

/*******************************************************************
 validateRangeMaxOnly function:
 This function accepts 2 int arguments representing an input value
 and maximum allowed value.  It returns an int.  It verifies if the
 supplied input is less than or equal to the allowed maximum value.
 *******************************************************************/
int InputValidation::validateRangeMaxOnly(int input, int maxValue)
{
    while(true)
    {
        if(input <= maxValue)
        {
            return input;
        }
        else
        {
            std::cout << "Invalid entry. Please try again: ";
            std::string newInput;
            getline(std::cin,newInput);
            input = validateInt(newInput);
        }
    }
    return input;
}
