/*
Shifra Schectman
CS162-Lab2
April 15, 2018
This program counts the number of each letter
in each paragraph of a file and outputs it to files.
*/

#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ostream;
using std::ofstream;
using std::string;

/*
 *  * This function takes the input stream and a 
 *   * pointer to the count array as arguments.
 *    * It then counts the number of each letter.
 *     * */
void count_letters(ifstream &inputStream, int* count)
{

	while (!inputStream.eof())
	{
		char ch = inputStream.get();

		if (ch >= 'a' && ch <= 'z')
		{
			count[ch - 'a']++;

		}
		else if (ch >= 'A'&& ch <= 'Z')
		{
			count[ch - 'A']++;
		}
		else if (ch == '\n')
		{
			return;
		}
	}
}

/*
 *  * This function takes the output stream and a
 *   * pointer to the count array as arguments.
 *    * It then outputs the frequency of the letter to a file.
 *     * */
void output_letters(ostream &outputStream, int* count)
{
		char ch = 'a';
		for (int i = 0; i < 26; i++)
		{
			outputStream << ch++ << ": " << count[i] << std::endl;
		}
}

int main()
{
	string fileName, newFile;
	int count[26];


	cout << "Please enter the name of the file you would like to open." << endl;
	cin >> fileName;

	ifstream inputStream(fileName.c_str());
	if (!inputStream)
	{
		cout << fileName << " does  not exist!" << endl;
		return 1;
	}

	while (!inputStream.eof())
	{
		for (int i = 0; i<26; i++)
		{
			count[i] = 0;
		}
		count_letters(inputStream, count);
		cout << "Please enter your output file name." << endl;
		cin >> newFile;
		ofstream outputStream(newFile.c_str());
		output_letters(outputStream, count);
	}
	return 0;
}



