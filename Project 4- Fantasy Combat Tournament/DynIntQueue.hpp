/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
*Dynamic Queue Class Header File
*/

#include "Character.hpp"
#ifndef DYNINTQUEUE_HPP
#define DYNINTQUEUE_HPP 
class DynIntQueue
{
private:
	struct QueueNode
	{
		Character *P;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(Character *Player, QueueNode *next1 = NULL, QueueNode *prev1 = NULL)
		{
			P = Player;
			next = next1;
			prev = prev1;
		}
	};
	QueueNode *head;
public:
	DynIntQueue();
	~DynIntQueue();
	bool isEmpty();
	void addBack(Character *P);
	Character* getFront();
	void removeFront();
	void printQueue();
};
#endif
