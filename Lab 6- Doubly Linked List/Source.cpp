/*
* Shifra Schectman
* May 13, 2018
* CS162 - Lab 6
* Source File
*/

#include "Linked.hpp"
#include "Menu.hpp"
#include <fstream>
#include <string>

int main()
{
	//create Menu instance
	Menu M;
	//create Linked instane
	Linked L;

	std::cout << "Extra Credit" << std::endl;

	//call textfile 
	int choice = M.textfile();
		if (choice == 1)
		{
			//open textfile
			std::ifstream inputStream;
			inputStream.open("ec.txt");
			//if no textfile, display message
			if (inputStream.fail())
			{
				std::cout << "No file." << std::endl;
				return 1;
			}
			//loop through file
			while (!inputStream.eof())
			{
				std::string str;
				getline(inputStream, str, '\n');
				// read up on how to convert a string to an int-cplusplus.com	
				int x = atoi(str.c_str());
				L.addToTail(x);			
			}
			//close file
			inputStream.close();
			
		}
		//if user does not use file, display message
		else if (choice == 2)
		{
			std::cout << "You have chosen not to use the file to create the linked list." << std::endl;
		}

	//initialize loop that displays menu while user wants to continue
	do
	{
		//switch statement for selection made by user
		switch (M.chooseFunction())
		{
		case 1:
			//call addToHead function with number input by user from menu class
			L.addToHead(M.enterNumber());
			break;
		case 2:
			//call addToTail function with number input by user from menu class
			L.addToTail(M.enterNumber());
			break;
		case 3:
			//call deleteFirst function
			L.deleteFirst();
			break;
		case 4:
			//call deleteLast function
			L.deleteLast();
			break;
		case 5:
			//call transreverse
			L.transreverse();
			std::cout << std::endl;
			break;
		case 6:
			//call printHead
			L.printHead();
			break;
		case 7:
			//call printTail
			L.printTail();
			break;
		}
	} while (M.continuePlaying() == 1);

}
