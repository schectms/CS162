/*
* Shifra Schectman
* May 27, 2018
* CS162 - Project 4
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
	if (isEmpty() == false)
	{
		QueueNode *curr = head->next;
		QueueNode *temp;
		while (curr != head)
		{
			temp=curr->next;
			//curr=temp;
			delete curr->P;
			delete curr;
			//move on to next node
			curr = temp;
		}
		delete head->P;
		delete head;
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
void DynIntQueue::addBack(Character *P)
{
	//create new node
	QueueNode* newNode = new QueueNode(P);
	//if list is empty
	if (isEmpty())
	{

		//set head to newnode
		head = newNode;
		//when only one item, node points to itself
		head->prev = head;
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
	}
}


/*
getFront function
returns the value at the front of the list
*/
Character* DynIntQueue::getFront()
{
	if (isEmpty())
	{
		std::cout << "Empty List" << std::endl;
		return 0;
	}
	else
	{
		return head->P;
	}
}

void DynIntQueue::removeFront()
{
	//QueueNode *newNode = head;
	//if there is no head, display warning that the list is empty
	if (isEmpty())
	{
		std::cout << "List is empty. No items to remove." << std::endl;
	}
	else if (head == head->prev)
	{
		head->prev = NULL;
		delete head;
		head = NULL;
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
		while (nptr->next != head)
		{
			//print the current node
			std::cout << nptr->P->getName() << " ";
			//move on to next node
			nptr = nptr->next;
		}
		//print the tail
		std::cout << head->prev->P->getName();
	}

}


