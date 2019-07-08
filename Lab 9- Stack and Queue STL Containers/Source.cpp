/*
* Shifra Schectman
* June 3, 2018
* CS162 - Lab 9
* Source File
*/
#include <queue>
#include <stack>
#include <time.h>
#include "Menu.hpp"

int main()
{
	//seed random
	srand(time(NULL));
	double prevAvg = 0;

	Menu M;
	//ask how many rounds and store in variable
	int numberOfRounds=M.enterNumber("How many rounds will be simulated?");
	//ask percentage that a number will be entered and store in variable
	int numberEntered = M.enterNumber("What is the percentage that a random number will be stored at the end of the buffer?");
	//ask percentage that a number will be removed and store in variable
	int numberRemoved= M.enterNumber("What is the percentage that a random number will be removed from the end of the buffer?");
	
	//declare queue 
	std::queue<int> QUEUE;
	
	for (int i = 0; i < numberOfRounds; i++)
	{
		//Generate a random number from 1 – 1000
		int N = rand() % 1000 + 1;

		//generate a random number from 1-100
		int appendNum = rand() % 100 + 1;

		//if  less than/equal to the user specified percentage for adding value, then append the number N into the queue
		if (appendNum <= numberEntered)
		{
			QUEUE.push(N);
		}

		//generate a random number from 1-100
		int removeNum = rand() % 100 + 1;

		//if  less than/equal to the user specified percentage for removing value, then remove the first element in the queue
		if (removeNum <= numberRemoved && QUEUE.size()>0)
		{
			QUEUE.pop();
		}
		
		std::cout << "ROUND " << i + 1 << std::endl;
		//create a copy of queue
		std::queue<int> QUEUE2;
		QUEUE2 = QUEUE;
		//output values in queue
		std::cout << "Values in Queue: " << std::endl;
		while (!QUEUE2.empty())
		{
			std::cout << QUEUE2.front() << " ";
			QUEUE2.pop();
		}
			std::cout << std::endl;
		//output size of queue
		std::cout << "Length of Queue: " << std::endl;
		std::cout <<QUEUE.size() << std::endl;
		std::cout << std::endl;
		
		//calculate average length
		if (i != 0)
		{
			prevAvg= (prevAvg*(i - 1) + QUEUE.size()) / i;
		}

	}
	
	//display average
	double average = prevAvg;
	std::cout << "Average Length of Buffer: " << average << "%" << std::endl;
	std::cout << std::endl;

	//enter string to be turned into palindrome
	std::string palindrome = M.enterString();
	//declare stack
	std::stack <char> STACK;
	//add char values to stack and print
	for (unsigned i = 0; i < palindrome.length(); i++)
	{
		std::cout << palindrome[i];
		STACK.push(palindrome[i]);
	}

	//remove values from stack and print
	while (!STACK.empty())
	{
		std::cout << STACK.top();
		STACK.pop();
	}
}
