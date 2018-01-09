/*
NAME: Christina Sadak
PROGRAM: Program 4: Quick Sort
DUE DATE: November 7th, 2017
PURPOSE: Tests the Quick Sort with various sizes of data passed in as command line arguments. Some code from Schaffer textbook and Thacker's PowerPoint
*/

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

void quicksort(string stringArray[], int L, int R);
int partition(string stringArray[], int L, int R, string& pivot);

int main(int numParams, char* commandParams[])
{

	 cout<<"Welcome to Program 4: Quick Sort"<<endl;

	 if(numParams!=2)//checks to make sure exactly two arguments are entered. Exits if not.
	 {
		 cout<<"Need 2 args."<<endl;
		 return 1;
	 }

	 int size = atoi(commandParams[1]);//turns the character passed in as the second command in the command line argument into an integer. This integer says how many items to pull from Thacker's file
	 string* stringArray;
	 stringArray = new string[size];//creates an array to hold the number of strings decided by the size entered in the command line

	 ifstream inFile;
	 inFile.open("/home/win.thackerw/271/sort.dat");//open's thacker's file

	 ofstream outFile;

	 if(!inFile.is_open())//checks to make sure the file can be opened. Exits if not
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

		 quicksort(stringArray, 0, size-1);//calls quick sort and passes it the array we filled from reading the correct number of elements from the file, and the size

		 outFile.open("sorted.dat");//opens a new file to output the sorted array into

		 for(int y=0; y<size; y++)
		 {
			 outFile<<stringArray[y]<<endl;//writes the sorted array to the output file
		 }
	 }


return 0;
}

void quicksort(string stringArray[], int L, int R)//function quick sort that takes the string array, and two integers to implement a divide and conquer technique. Recursive.
//divides the original array into three pieces. Things less than pivot, things greater than pivot, the pivot
//L and R function as the start and stop of the part of the BIG array we're working with
//expects inclusive boundaries
//called with new boundaries each time
{
	int pivotIndex = (L + R)/2;//creates a new pivot each iteration. The middle.
	swap(stringArray[pivotIndex], stringArray[R]); //if the pivot value is greater than the right value, swap. Puts pivot at the end and puts up a fence
	int newLow = partition(stringArray, L-1, R, stringArray[R]);//newLow is set by calling partition which determines the new left value. Expects boundaries exclusive. Last value passed is the pivot
	swap(stringArray[newLow], stringArray[R]);//puts pivot in the lowest index of the piece of greater values in the array. Position newLow never has to be touched again

	if((newLow-L)>1)//do this if the size of the left subarray is > 1 because if it's size 1 then it's done
		quicksort(stringArray, L, newLow-1);//first position in left subarray is L. Left sub array ends at newLow-1. Size of left side is (newLow-1) +1 = k-I
	if((R-newLow)>1)//do this if the size of the right subarray is > 1.
		quicksort(stringArray, newLow+1, R);//sorts right subarray starting at position newLow+1. Size = R-(k+1) = (stop-start)+1
}

int partition(string stringArray[], int L, int R, string& pivot)//partition function that determines how to divide the array into smaller problems
{//gets everything less than pivot to one side and everything greater than pivot to other side. Not necessarily even.
	do{

		while(stringArray[++L] < pivot);//preincrements because we're using stringArray inclusively. Goes until left is no longer less than the pivot value
		while(R && (stringArray[--R] > pivot));//preincrements because we're using stringArray inclusively. Goes until right is no longer greater than the pivot value
		swap(stringArray[L], stringArray[R]);//swaps the value of left and right in the array

	}while(L < R);//if left ever becomes greater than or equal to right, then the array before that happened is the correct new partition

	swap(stringArray[L], stringArray[R]);//L has passed R to get out of the while loop, so now they must be swapped back

	return L;//returns L. L is where the groups separate. L is the first thing in the bigger group.
}
