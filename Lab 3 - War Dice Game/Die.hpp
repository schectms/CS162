/*
* Shifra Schectman
* Lab 3
* Die Class Header File
* April 22, 2018
*/
#ifndef DIE_HPP
#define DIE_HPP
#include <cstdlib>
#include <time.h>

class Die
{
protected:
	int N;
public:
	Die(int NIn)
	{
		N = NIn;
	}

	int getNumberOfSides()
	{
		return N;
	}

	/*
	* This function takes the number of sides
	* as a parameter and returns a random number
	* between 1 and the number of sides
	*/
	virtual int spinDie(int N)
	{
		int result = rand() % N + 1;
		return result;
	}
};

class LoadedDie :public Die
{
public:
	LoadedDie(int NIn) : Die(NIn)
	{
	}

	/*
	* This function takes the number of sides
	* as a parameter and returns the highest 
	number on the die
	*/
	int spinDie(int N)
	{
		int result = N;
		return result;
	}
};

#endif


