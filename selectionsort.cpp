/*
NAME: Christina Sadak
PROGRAM: Program 4: Selection Sort
DUE DATE: November 7th, 2017
PURPOSE: Tests the Selection Sort with various sizes of data passed in as command line arguments. Some code from Schaffer textbook and Thacker's PowerPoint
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

void selectionsort(string stringArray[], int size);

int main(int numParams, char* commandParams[])
{

	 cout<<"Welcome to Program 4: Selection Sort"<<endl;

	 if(numParams!=2)//checks to make sure exactly two arguments are entered. Exits if not.
	 {
		 cout<<"Need 2 args."<<endl;
		 return 1;
	 }

	 int size = atoi(commandParams[1]);;//turns the character passed in as the second command in the command line argument into an integer. This integer says how many items to pull from Thacker's file
	 string* stringArray;
	 stringArray = new string[size];//creates an array to hold the number of strings decided by the size entered in the command line

	 ifstream inFile;
	 inFile.open("/home/win.thackerw/271/sort.dat");//open's thacker's file

	 ofstream outFile;

	 if(!inFile.is_open())//checks to make sure the file can be opened. Exits if not.
	 {
		 cout<<"Failed opening file. Exiting.";
		 return 1;
	 }

	 else
	 {
		 for(int x=0; x<size; x++)//loops through until we have read the correct number of element's from thacker's file into our array of strings
		 {
			 inFile>>stringArray[x];
		 }

		 selectionsort(stringArray, size);//calls selection sort and passes it the array we filled from reading the correct number of elements from the file, and the size

		 outFile.open("sorted.dat");//opens a new file to output the sorted array into

		 for(int y=0; y<size; y++)
		 {
			 outFile<<stringArray[y]<<endl;//writes the sorted array to the output file
		 }

	 }


return 0;
}

void selectionsort(string stringArray[], int size)//function selection sort that takes the stringArray and the size
{
	for(int i=0; i<size-1; i++)//loops forward through the array until one before the end
	{
		int lowIndex = i;//sets low index to the first item in list and updates at each iteration
		for(int j=size-1; j>i; j--)//loops backwards through the array until one before the begining
		{
			if(stringArray[j]<stringArray[lowIndex])//if the value from the further position in the array is less than the value in the lower position in the array, swap them
			{
				swap(stringArray[j], stringArray[lowIndex]);
			}
		}
	}
}
