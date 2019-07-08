/*
 * Shifra Schectman
 * CS162-Lab 10
 * June 10, 2018
 * Source File
 * 
 * Citations-
 * Title: Fibonacci Recursive and Non Recursive C++
 * Author:josepharul83@gmail.com
 * 18 Sep 2010
 * https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
 *
 * Title: How to Measure Execution Time Intervals in C++
 * Author: Giovanni Dicanio
 * 15 July 2016
 * https://www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
 */
#include <stdio.h>
#include <time.h> 
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
#include <sstream>

int enterNum()
{
	bool errFlag = false;
	std::string input;
	int choice;

	do
	{
		std::cout << "Enter a number: "<< std::endl;
		getline(std::cin, input);
		std::stringstream sStream(input);
		if (sStream >> choice && !(sStream >> input))
		{
			errFlag = true;
		}
		else
		{
			system("clear");
		}
	} while (errFlag == false);
	return choice;
}
void Usage() {
std::cout << "Correct Usage:" << std::endl;
std::cout << "./Fibonacci [n]" << std::endl;
}

int main(int argc, char** args) {
	using std::chrono::system_clock;
	try {
		const char* input; 
		if (args[1] != 0)
		{
			std::cout << "1st passed arguement: '" << args[1] << "'" << std::endl;
			input = args[1];
		}
		int n=enterNum();
		std::cout << "Finding '" << n << "'th " << "fibonacci number...." << std::endl;
		auto startR = std::chrono::high_resolution_clock::now();
		std::cout << "Calling Recursive Fibonacci implementation" << std::endl;
		FibonacciR fr(n);
		fr.PrintFibonacci();
		auto finishR =std::chrono::high_resolution_clock::now(); 	
		auto startNR = std::chrono::high_resolution_clock::now();
		std::cout << "Calling Non-Recursive Fibonacci implementation" << std::endl;
		FibonacciNR fnr(n);
		fnr.PrintFibonacci();
		auto finishNR = std::chrono::high_resolution_clock::now();
		std::cout << "Done!!!!" << std::endl;
		std::chrono::duration<double> elapsed = finishR - startR;
		std::cout << "Elapsed time for recursive: " << elapsed.count() << " s\n";
		std::chrono::duration<double> elapsedNR = finishNR - startNR;
		std::cout << "Elapsed time for nonrecursive: " << elapsedNR.count() << " s\n";
		return 0;
	}
	catch (...)
	{
		std::cout << "Oops an error occured! Please check usage" << std::endl;
		Usage();
		return 1;
	}

}
