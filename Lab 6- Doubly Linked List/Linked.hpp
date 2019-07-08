/*
* Shifra Schectman
* May 13, 2018
* CS162 - Lab 6
* Linked Class Header File
*/

#include <iostream>

#ifndef LINKED_HPP
#define LINKED_HPP

class Linked
{
protected:

	/*
	listNode structure
	*/
	struct listNode
	{
		int value;
		listNode *next;
		listNode *prev;
		//default constructor that takes valueIn, next1, prev1 as aparemeters and sets the value of the listNode
		listNode(int valueIn, listNode *next1 = NULL, listNode *prev1 = NULL)
		{
			value = valueIn;
			next = next1;
			prev = prev1;
		}
	};

	listNode *head;
	listNode *tail;

public:
	Linked();
	~Linked();
	void transverse();
	void transreverse();
	void addToHead(int number);
	void addToTail(int number);
	void printHead();
	void printTail();
	void deleteFirst();
	void deleteLast();
};
#endif

