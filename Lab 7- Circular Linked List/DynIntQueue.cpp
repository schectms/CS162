/*
* Shifra Schectman
* May 20, 2018
* CS162 - Lab 7
*Dynamic Queue Class Source  File
*/

#include "DynIntQueue.hpp"

/*
default constructor, sets head to null
*/
DynIntQueue::DynIntQueue()
{
	head = NULL;
}

/*
destructor, deletes memory
*/

DynIntQueue::~DynIntQueue()
{
	if(isEmpty()==false)
	{
	QueueNode *garbage=head;
	while(garbage->next!=head)
	{		delete garbage;	
			//move on to next node
			garbage=garbage->next;
		}
		//print the tail
		delete head->prev;
	}
	}

/*
isEmpty function
checks to see if the list has any nodes and returns boolean value
*/
bool DynIntQueue::isEmpty()
{
	//if head is null, return true
	if (head == NULL)
	{
		return true;
	}
	//otherwise, return false
	else
	{
		return false;
	}
}

/*
addBack function 
takes a value as a parameter and adds it to the end of the list
*/
void DynIntQueue::addBack(int val)
{
	//create new node
	QueueNode* newNode = new QueueNode(val);
	//if list is empty
	if (isEmpty())
	{
		
		//set head to newnode
		head = newNode;
		//when only one item, node points to itself
		head->prev= head;
		head->next = head;
	}
	else
	{
	//set newNode->prev and newNode->next
	newNode->prev = head->prev;
	newNode->next = head;
	//set head and head->prev
	head->prev->next = newNode;
	head->prev = newNode;
	if (head->next == NULL)
	{
		head->prev = head;
	}
	}
}
/*
getFront function
returns the value at the front of the list
*/
int DynIntQueue::getFront()
{
	return head->value;
}

void DynIntQueue::removeFront()
{
	//QueueNode *newNode = head;
	//if there is no head, display warning that the list is empty
	if (isEmpty())
	{
		std::cout << "List is empty. No items to remove." << std::endl;
	}
	else if(head==head->prev)
	{
		head->prev=NULL;
		delete head;
		head=NULL;
	}
	else
	{
		//create new node
		QueueNode *newNode = head;
		//set head to second node
		head = head->next;
		//set tail to new tail
		head->prev = newNode->prev;
		newNode->prev->next = head;
		//delete node
		delete newNode;
	}
}
/*
printQueue function
prints the list 
*/
void DynIntQueue::printQueue()
{
	//if the list is empty, display message
	if (isEmpty())
	{
		std::cout << "The list is empty." << std::endl;
	}
	else
	{
		//start at head of list
		QueueNode *nptr = head;
		//while there are nodes 
		while (nptr->next!=head)
		{
			//print the current node
			std::cout << nptr->value << " ";
			//move on to next node
			nptr = nptr->next;
		}
		//print the tail
		std::cout << head->prev->value;
	}
	
}


