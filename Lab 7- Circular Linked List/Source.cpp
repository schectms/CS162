/*
* Shifra Schectman
* May 20, 2018
* CS162 - Lab 7
* Source File
*/

#include "DynIntQueue.hpp"
#include "Menu.hpp"


int main()
{
	//create Menu instance
	Menu M;
	//create DynIntQueue instane
	DynIntQueue D;
		
	//initialize loop that displays menu while user wants to continue
	do
	{
		int choice=M.chooseFunction();
		//switch statement for selection made by user
		switch (choice)
		{
		case 1:
			//call addBAck function with number input by user from menu class
			D.addBack(M.enterNumber());
			break;
		case 2:
			//if list is empty, display message
			if (D.isEmpty())
			{
				std::cout << "List is empty." << std::endl;
			}
			//otherwise, call getFront function
			else
			{
				std::cout << D.getFront() << std::endl;
			}
			break;
		case 3:
			//call removeFront function
			D.removeFront();
			break;
		case 4:
			//call printQueue function
			D.printQueue();
			std::cout << std::endl;
			break;
		case 5:
			std::cout << "Exiting Menu."<<std::endl;
			break;
		}

	} while (M.continuePlaying()==1);

}
