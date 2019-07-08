/*
* Shifra Schectman
* May 20, 2018
* CS162 - Lab 7
*Dynamic Queue Class Header File
*/
#include <iostream>
#ifndef DYNINTQUEUE_HPP
#define DYNINTQUEUE_HPP 
class DynIntQueue
{
private:
	struct QueueNode
	{
		int value;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(int value1, QueueNode *next1= NULL, QueueNode *prev1=NULL)
		{
			value = value1;
			next = next1;
			prev = prev1;
		}
	};
	QueueNode *head;
public:
	DynIntQueue();
	~DynIntQueue();
	bool isEmpty();
	void addBack(int val);
	int getFront();
	void removeFront();
	void printQueue();
};
#endif
