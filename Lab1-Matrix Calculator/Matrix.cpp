/*
 * Shifra Schectman
 * January 15, 2018
 * This function takes a pointer to the matrix and the size as a parameter and then prompts the user to fill the matrix. It then displays the matrix.  
*/
 #include <iostream>

void readMatrix(int** matrix, int size)
{
	//prompt the user to input numbers to fill the matrix
	std::cout << "Enter " << (size*size) << " numbers to fill the  matrix" << std::endl;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
		{
			std::cin>>matrix[i][j];
		}
	//print the matrix
	std::cout<<std::endl;
	std::cout<<"Matrix:"<<std::endl;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			std::cout << matrix[i][j];
		}
	std::cout <<std::endl;
	}
}
