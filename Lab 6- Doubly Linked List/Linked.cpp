/*
* Shifra Schectman
* May 13, 2018
* CS162 - Lab 6
* Linked Class Source File
*/

#include "Linked.hpp"

/*
default constuctor that sets the head and tail to null
*/
Linked::Linked()
{
	head = tail = NULL;
}

/*
destructor that frees memory
*/
Linked::~Linked()
{
	//begin at head
	listNode *nptr = head;
	//while there are nodes
	while (nptr != NULL)
	{
		//garbage tracks node to be deleted
		listNode *garbage = nptr;
		//move to next node
		nptr = nptr->next;
		//delete memory
		delete garbage;
	}
}

/*
transverse
loops through the list and displays all the nodes
*/
void Linked::transverse()
{
	//if the list is empty, display message
	if (!head)
	{
		std::cout << "The list is empty." << std::endl;
	}
	//start at head of list
	listNode *nptr = head;
	//while there are nodes
	while (nptr)
	{
		//print the current node
		std::cout << nptr->value << " ";
		//move on to next node
		nptr = nptr->next;
	}
}

/*
transreverse
loops through the list and displays all the nodes in reverse
*/
void Linked::transreverse()
{
	//if the list is empty, display message
	if (!head)
	{
		std::cout << "The list is empty." << std::endl;
	}
	//start at tail of list
	listNode *nptr = tail;
	//while there are nodes
	while (nptr)
	{
		//print the current node
		std::cout << nptr->value << " ";
		//move on to next node
		nptr = nptr->prev;
	}

}

/*
addToHead
takes an int as a paremeter and adds a node of that value to the head of the list
*/
void Linked::addToHead(int number)
{
	//create newNode to track new node
	listNode* newNode = new listNode(number);
	//set next to head
	newNode->next = head;
	//set prev to null
	newNode->prev = NULL;
	//when the list is empty
	if (head == NULL)
	{
		//set tail and head to newnode
		tail = head = newNode;
	}
	//otherwise
	else if (head != NULL)
	{
		//set value of head to newnode and head to the first node
		head->prev = newNode;
		head = newNode;
	}
	//print the list with the added number
	transverse();
	std::cout << std::endl;

}

/*
addToTail
takes an int as a paremeter and adds a node of that value to the tail of the list
*/
void Linked::addToTail(int number)
{
	//create newNode to track new node
	listNode* newNode = new listNode(number);
	//set prev to tail
	newNode->prev = tail;
	//set next to null
	newNode->next = NULL;
	//if the list is empty
	if (tail == NULL)
	{
		//head and tail equal newnode
		head = tail = newNode;
	}
	//otherwise
	else if (tail != NULL)
	{
		//set value of tail to newnode and tail to the first node
		tail->next = newNode;
		tail = newNode;
	}
	transverse();
	std::cout << std::endl;
}

/*
printHead
prints the value of the head
*/
void Linked::printHead()
{
	//if there is a head, print the value
	if (head)
	{
		std::cout << "HEAD: " << head->value << std::endl;
	}
	//otherwise, print message that the list is empty
	else
	{
		std::cout << "The list is empty" << std::endl;
	}
}

/*
printTail
prints the value of the tail
*/
void Linked::printTail()
{
	//if there is a tail, print the value
	if (tail)
	{
		std::cout << "TAIL: " << tail->value << std::endl;
	}
	//otherwise, print message that the list is empty
	else
	{
		std::cout << "The list is empty" << std::endl;
	}
}

/*
deleteFirst
deletes the first node in list
*/
void Linked::deleteFirst()
{
	//if there is no head, display warning that the list is empty
	if (!head)
	{
		std::cout << "Warning! This list has no elements, so none can be deleted." << std::endl;
	}
	//if there is only one element, set both head and tail to null
	else if (head->next == NULL)
	{
		tail = head = NULL;
		transverse();
	}
	//if there are 2 or more elements
	else
	{
		//create new node
		listNode *newNode = head;
		//set head to second node
		head = newNode->next;
		// set prev head to null
		head->prev = NULL;
		//delete node
		delete newNode;
		//if there is now one nde, set tail to head
		if (head->next == NULL)
		{
			tail = head;
		}
		//call transverse function
		transverse();
	}
}

/*
deleteLast
deletes the last node in the list
*/
void Linked::deleteLast()
{
	//if there is no tail, display warning that the list is empty
	if (!tail)
	{
		std::cout << "Warning! This list has no elements, so none can be deleted." << std::endl;
	}
	//if there is only one element, set both head and tail to null
	else if (tail->prev == NULL)
	{
		tail = head = NULL;
		transverse();
	}
	//if there are 2 or more elements
	else
	{
		//create new node
		listNode *newNode = tail;
		//set tail to second node
		tail = newNode->prev;
		// set prev tail to null
		tail->next = NULL;
		//delete node
		delete newNode;
		//if there is now one nde, set tail to head
		if (tail->prev == NULL)
		{
			tail = head;
		}
		//call transverse function
		transverse();
	}
}
