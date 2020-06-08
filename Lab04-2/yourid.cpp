// Lab04-02
// Created by Jesus Vera
// Copyright © 2020 UC Merced. All rights reserved.
#include <iostream>
#include <cstdlib>
using namespace std;

/*This method is used to swap two value references passed to it*/
void swapValues(int &value1, int &value2) {
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

/*The method is used to partition the array on the pivot,
rotate the pivot adn print the results*/
int partateArrayOnPivot(int dataArray[], int startingIndex, int endingIndex) {
	int iter1, middlePoint;
	iter1 = startingIndex - 1;
	middlePoint = dataArray[endingIndex];	
	int iter2;
	for (iter2 = startingIndex; iter2 <= (endingIndex - 1); iter2++)
		if (dataArray[iter2] <= middlePoint) {
			iter1++;
			swapValues(dataArray[iter1], dataArray[iter2]);
		}
	swapValues(dataArray[iter1 + 1], dataArray[endingIndex]);
	iter1 += 1;
	return iter1;
}

/*The following method sorts the given array by calling the pivot function,
after pivoting rotate the values and then print the results*/
void quickSortArray(int dataArray[], int startingIndex, int endingIndex) {
	if (startingIndex < endingIndex) { 
		int iter1 = (rand() % (endingIndex - startingIndex)) + startingIndex;
		swapValues(dataArray[endingIndex], dataArray[iter1]);
		int meanPoint = partateArrayOnPivot(dataArray, startingIndex, endingIndex);
		quickSortArray(dataArray, startingIndex, meanPoint - 1); 
		quickSortArray(dataArray, meanPoint + 1, endingIndex);
	}
}

/*The following method is used to take input the arrays*/
void takeInputArray(int *dataArray, int countOfNumbers) {
	for (int iter1 = 0; iter1<countOfNumbers; iter1++) {
		cin >> dataArray[iter1];
	}
}

/*The following method is used to print the results*/
void printArray(int *dataArray, int countOfNumbers) {
	for (int iter1 = 0; iter1 < countOfNumbers; iter1++) {
		cout << dataArray[iter1] << ";";
	}
}

/*Main driver function to test the results*/
int main() {
	//declare array, and take input numbers
	int countOfNumbers, *dataArray;
	cin >> countOfNumbers; 
	//initiaze the array
	dataArray=new int[countOfNumbers];
	takeInputArray(dataArray, countOfNumbers);
	quickSortArray(dataArray, 0, countOfNumbers - 1);
	printArray(dataArray, countOfNumbers);
	return 0;
}
