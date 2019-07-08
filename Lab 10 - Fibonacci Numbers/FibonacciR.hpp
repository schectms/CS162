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

#include <iostream>
#ifndef FIBONACCIR_HPP
#define FIBONACCIR_HPP
class FibonacciR {
public:
FibonacciR(const int &n);
virtual ~FibonacciR();
void PrintFibonacci();
private:
FibonacciR();
int Fibonacci(const int &n);
const int *n_;
};
#endif
