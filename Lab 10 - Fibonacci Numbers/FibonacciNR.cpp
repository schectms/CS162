#/*
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
 */
#include "FibonacciNR.hpp"
#include <iostream>
FibonacciNR::FibonacciNR() {}
FibonacciNR::FibonacciNR(const int &n) :n_(&n) {}
FibonacciNR::~FibonacciNR() {}
int FibonacciNR::Fibonacci(const int &n)
{
int first = 0;
int second = 1;
int counter = 2;
while (counter < n)
{
int temp = second;
second = first + second;
first = temp;
++counter;
}
if (n == 0)
return 0;
else
return first + second;
}
void FibonacciNR::PrintFibonacci() {
const int result = Fibonacci(*n_);
std::cout << *n_ << "th fibonacci Number:" << result << std::endl;
}
