/*
* Shifra Schectman
* May 27, 2018
* CS162 - Lab 8
* Source File
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Menu.hpp"
#include "Functions.hpp"




int main()
{
	Functions f;
	Menu m;
	std::vector <int> early;
	std::vector <int> middle;
	std::vector <int> end;
	std::vector <int> orig;

	std::ifstream inputStream;
	//opens early.txt
	inputStream.open("early.txt");
	//if no textfile, display message
	if (inputStream.fail())
	{
		std::cout << "No file." << std::endl;
		return 1;
	}
	int x;
	//reads values from file
	while (inputStream >>x)
	{
		early.push_back(x);
	}
	//close file
	inputStream.close();

	//open file
	inputStream.open("end.txt");
	//if fails, display message
	if (inputStream.fail())
	{
		std::cout << "No file." << std::endl;
		return 1;
	}
	//reads values from file
	while (inputStream >> x)
	{
		end.push_back(x);
	}
	//close file
	inputStream.close();

	//open file
	inputStream.open("middle.txt");
	//if fail
	if (inputStream.fail())
	{
		std::cout << "No file." << std::endl;
		return 1;
	}
	//reads values from file
	while (inputStream >> x)
	{
		middle.push_back(x);
	}
	//close file
	inputStream.close();

	//open file
	inputStream.open("orig.txt");
	//if fail
	if (inputStream.fail())
	{
		std::cout << "No file." << std::endl;
		return 1;
	}
	//reads values from file
	while (inputStream >> x)
	{
		orig.push_back(x);
	}
	//close file
	inputStream.close();
			
	//call enterValue
	int val=m.enterValue();
		
		//call search function for each file and output whether the target value was found
			int pos = f.search(end, val);
			if (pos == -1)
			{
				std::cout << "Target value not found in 'end.txt'." << std::endl;
			}
			else
			{
				std::cout << "Target value found in 'end.txt'." << std::endl;
			}

			pos = f.search(early, val);
			if (pos == -1)
			{
				std::cout << "Target value not found in 'early.txt'." << std::endl;
			}
			else
			{
				std::cout << "Target value found in 'early.txt'." << std::endl;
			}

			pos = f.search(middle, val);
			if (pos == -1)
			{
				std::cout << "Target value not found in 'middle.txt'." << std::endl;
			}
			else
			{
				std::cout << "Target value found in 'middle.txt'." << std::endl;
			}
			pos = f.search(orig, val);
			if (pos == -1)
			{
				std::cout << "Target value not found in 'orig.txt'." << std::endl;
			}
			else
			{
				std::cout << "Target value found in 'orig.txt'." << std::endl;
			}

			//ask user which file to sort
			std::string fileName;
			std::cout << "Enter file name: " << std::endl;
			std::ofstream output;
			getline(std::cin, fileName);
			{
				if (fileName == "early.txt")
				{
					f.sort(early);
					output.open("early.txt");
					for (unsigned i = 0; i < early.size(); i++)
					{
						output << early[i] << '\n';
					}
					f.showVector(early);

					//binary search
					val = m.enterValue();

					int results = f.binarySearch(early, val);
					if (results == -1)
					{
						std::cout << "Target value not found." << std::endl;
					}
					else
					{
						std::cout << "Target value found." << std::endl;
					}

				}
				else if (fileName == "end.txt")
				{

					f.sort(end);
					output.open("end.txt");
					for (unsigned i = 0; i < end.size() - 1; i++)
					{
						output << end[i] << '\n';
					}
					//output to file
					f.showVector(end);

					//binary search
					val = m.enterValue();

					int results = f.binarySearch(end, val);
					if (results == -1)
					{
						std::cout << "Target value not found." << std::endl;
					}
					else
					{
						std::cout << "Target value found." << std::endl;
					}

				}
				else if (fileName == "orig.txt")
				{
					f.sort(orig);
					output.open("orig.txt");
					for (unsigned i = 0; i < orig.size() - 1; i++)
					{
						output << orig[i] << '\n';
					}
					f.showVector(orig);

					//binary search
					val = m.enterValue();

					int results = f.binarySearch(orig, val);
					if (results == -1)
					{
						std::cout << "Target value not found." << std::endl;
					}
					else
					{
						std::cout << "Target value found." << std::endl;
					}

				}
				else if (fileName == "middle.txt")
				{
					f.sort(middle);
					output.open("middle.txt");
					for (unsigned i = 0; i < middle.size() - 1; i++)
					{
						output << early[i] << '\n';
					}
					f.showVector(middle);

					//binary search
					val = m.enterValue();

					int results = f.binarySearch(middle, val);
					if (results == -1)
					{
						std::cout << "Target value not found." << std::endl;
					}
					else
					{
						std::cout << "Target value found." << std::endl;
					}

				}
				else
				{
					std::cout << "No file found." << std::endl;
				}
				output.close();

			}


}
