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
 */
#include "FibonacciR.hpp"
FibonacciR::FibonacciR() {}
FibonacciR::FibonacciR(const int &n) :n_(&n) {}
FibonacciR::~FibonacciR() {}
int FibonacciR::Fibonacci(const int &n) {
if (n == 0)
return 0;
else if (n == 1)
return 1;
return Fibonacci(n - 1) + Fibonacci(n - 2);
}
void FibonacciR::PrintFibonacci() {
int FibonaciNum = Fibonacci(*n_);
std::cout << *n_ << "th fibonaci number: " << FibonaciNum << std::endl;
}
