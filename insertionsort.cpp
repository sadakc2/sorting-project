/*
NAME: Christina Sadak
PROGRAM: Program 4: Insertion Sort
DUE DATE: November 7th, 2017
PURPOSE: Tests the Insertion Sort with various sizes of data passed in as command line arguments. Some code from Schaffer textbook and Thacker's PowerPoint
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

void insertionsort(string stringArray[], int size);

int main(int numParams, char* commandParams[])
{

	 cout<<"Welcome to Program 4: Insertion Sort"<<endl;

	 if(numParams!=2)//exits if not exactly two commands were entered in the command line
	 {
		 cout<<"Need 2 args."<<endl;
		 return 1;
	 }

	 int size = atoi(commandParams[1]);//turns the character passed in as the second command in the command line argument into an integer. This integer says how many items to pull from Thacker's file
	 string* stringArray;
	 stringArray = new string[size];//creates an array to hold the number of strings decided by the size entered in the command line

	 ifstream inFile;
	 inFile.open("/home/win.thackerw/271/sort.dat");//open thacker's file

	 ofstream outFile;

	 if(!inFile.is_open())//exits if file failed to open
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

		 insertionsort(stringArray, size);//calls insertion sort and passes it the array we filled from reading the correct number of elements from the file, and the size

		 outFile.open("sorted.dat");

		 for(int y=0; y<size; y++)
		 {
			 outFile<<stringArray[y]<<endl;//writes the sorted array to the output file
		 }
	 }


return 0;
}

void insertionsort(string stringArray[], int size)
{
  for(int x=1; x<size; x++)//loops through until it's gone through the designated too
  {
    for(int y=x; (y>0) && (stringArray[y])<stringArray[y-1]; y--)//keeps from hitting the 0th element.
    swap(stringArray[y], stringArray[y-1]);//swaps the values of y and y-1
  }
}
