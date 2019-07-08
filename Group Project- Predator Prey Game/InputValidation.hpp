/*******************************************************************
 ** Program Name: InputValidation Class
 ** Author: Rebecca Vickers
 ** Date: 4/12/2018
 ** Description: This declaration file for the InputValidation
 class declares methods to validate if an input is an integer,
 validate if it is within a certian range, or greater than a min value,
 or greater than a max value.  Function design informed by:
 http://www.cplusplus.com/forum/articles/6046/
 *******************************************************************/

#ifndef InputValidation_hpp
#define InputValidation_hpp
#include <string>
#include <sstream>
#include <iostream>

class InputValidation
{
private:
    
public:
    int validateInt(std::string input);
    int validateRange(int input, int minValue, int maxValue);
    int validateRangeMinOnly(int input, int minValue);
    int validateRangeMaxOnly(int input, int maxValue);
    int validateExactInteger(int requiredInteger, int inputInteger);

};


#endif /* InputValidation_hpp */
