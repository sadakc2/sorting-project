/*
NAME: Christina Sadak
PROGRAM: Program 4: Merge Sort
DUE DATE: November 7th, 2017
PURPOSE: Tests the Merge Sort with various sizes of data passed in as command line arguments. Some code from Schaffer textbook and Thacker's PowerPoint
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

void mergesort(string stringArray[], string tempArray[], int left, int right);

int main(int numParams, char* commandParams[])
{
	 cout<<"Welcome to Program 4: Merge Sort"<<endl;

	 if(numParams!=2)//exits if not exactly two commands were entered
	 {
		 cout<<"Need 2 args."<<endl;
		 return 1;
	 }

	 int size = atoi(commandParams[1]);//turns the character passed in as the second command in the command line argument into an integer. This integer says how many items to pull from Thacker's file
	 string* stringArray;
   string* tempArray;
	 stringArray = new string[size];//creates an array to hold the number of strings decided by the size entered in the command line
   tempArray = new string[size];//creates a temporary array to hold the number of strings decided by the size entered in the command line

	 ifstream inFile;
	 inFile.open("/home/win.thackerw/271/sort.dat");//opens Thacker's file

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

		 mergesort(stringArray, tempArray, 0, size-1);

		 outFile.open("sorted.dat");

		 for(int y=0; y<size; y++)
		 {
			 outFile<<stringArray[y]<<endl;//writes the sorted array to the output file
		 }
	 }


return 0;
}

void mergesort(string stringArray[], string tempArray[], int left, int right)//mergesort splits the array into two subarrays, sorts each, and then puts them back together. recursive
{
  int i, j, k;
	int mid = (left + right)/2;//sets mid

  if(left==right)
  {
    return;
  }

  mergesort(stringArray, tempArray, left, mid);
  mergesort(stringArray, tempArray, mid+1, right);
  for(i=left; i<=mid; i++)//fills left side of temporary array with appropriate values from the big array
	{
		tempArray[i] = stringArray[i];
	}
  for(j=1; j<=right-mid; j++)//fills right side of temporary array with appropriate values from the big array
	{
		tempArray[right-j+1]=stringArray[j+mid];
	}
	i=left;//resets left
	j=right;//resets right
	for(k=left; k<=right; k++)//finds where the temporary array is split between right and left depending on the mid value, and then sets index at stringArray[k] to the appropriate index from tempArray
	{
		if(tempArray[i]<tempArray[j])
			stringArray[k]=tempArray[i++];
		else
			stringArray[k]=tempArray[j--];
	}
}
