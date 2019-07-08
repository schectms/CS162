/*
* Shifra Schectman
* May 27, 2018
* CS162 - Lab 8
* Functions Source File
*/

#include "Functions.hpp"

/*
search function
takes the vector and a value as a parameter and tries to find the value in the vector
*/
int Functions::search(std::vector<int>vect, int value)
{
	//use i as a subscript to search array
	unsigned i = 0;
	//record position of search value
	int position = -1;
	//flag to indicate if value was found
	bool found = false;

	while (i < vect.size() && !found)
	{
		//if the value is found
		if (vect[i] == value)
		{
			//set the flag
			found = true;
			//record the values subscript
			position = i;
		}
		//go to the next element
		i++;
	}
	//return the position or -1
	return position;
}

/*
showVector function takes vector as a parameter and displays its values
*/
void Functions::showVector(std::vector<int>vect)
{
	//loop theough vector
	for (unsigned i = 0; i < vect.size(); i++)
	{
		//display value at i
		std::cout << vect[i] << " ";
	}
	//output empty line
	std::cout << std::endl;
}

/*
sort function takes reference to vector as a paremter and sorts the value inside it
*/
void Functions::sort(std::vector<int> &vect)
{
	int temp;
	//swap will record if something has been swapped or not
	bool swap;
	do
	{
		swap = false;
		//loop throught the vector
		for (unsigned i = 0; i < (vect.size() - 1); i++)
		{
			//if a spot is bigger than the next one
			if (vect[i]>vect[i + 1])
			{
				//use temp to store i
				temp = vect[i];
				//set i to i+1
				vect[i] = vect[i + 1];
				//i+1 =temp
				vect[i + 1] = temp;
				//set flag
				swap = true;
			}
		}
	} while (swap);
}

/*
binary Search function takes vector and value as a parameter and locates the value in an ordered vector
*/
int Functions::binarySearch(std::vector<int> vect, int value)
{
	//first element
	int first = 0;
	//last element
	int last = vect.size() - 1;
	//midpoint
	int middle;
	//position of search value
	int position = -1;
	//flag
	bool found = false;

	while (!found && first <= last)
	{
		//calculate midpoint
		middle = (first + last) / 2;
		//if value is found at mid
		if (vect[middle] == value)
		{
			found = true;
			position = middle;
		}
		//if value is in lower half
		else if (vect[middle] > value)
		{
			last = middle - 1;
		}
		//if value is in upper half
		else
		{
			first = middle + 1;
		}
		
	}
	return position;

}
