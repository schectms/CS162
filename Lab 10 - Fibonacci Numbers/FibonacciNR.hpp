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
#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

class FibonacciNR {
public:
FibonacciNR(const int &n);
virtual ~FibonacciNR();
void PrintFibonacci();
private:
FibonacciNR();
int Fibonacci(const int &n);
const int* n_;
};
#endif 
