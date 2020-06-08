// Lab04-01
// Created by Jesus Vera 
// Copyright © 2020 UC Merced. All rights reserved.
#include <iostream>
using namespace std;

/* This function is used to swap two vlues by reference */
void swapValues(int &value1, int &value2) {
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

/* This function maps a given array on a max heap, and then applies the heapify on it */
void heapifyAtMax(int dataArray[], int arraySize, int iter1) {
	int lowIndex, highIndex, maximumValue;
	lowIndex = 2 * iter1; 
	highIndex = 2 * iter1 + 1; 
	if (lowIndex < arraySize && dataArray[lowIndex] > dataArray[iter1]) 
		maximumValue = lowIndex;
	else 
		maximumValue = iter1; 
	if (highIndex < arraySize && dataArray[highIndex] > dataArray[maximumValue]) 
		maximumValue = highIndex;
	if (maximumValue != iter1) { 
		swapValues(dataArray[iter1], dataArray[maximumValue]);
		heapifyAtMax(dataArray, arraySize, maximumValue);
	}
}

/* This function is used to take user input into the array */
void takeInputNumbers(int *dataArray, int countOfNumbers) {
	for (int iter1 = 0; iter1 < countOfNumbers; iter1=iter1+1) {
		cin >> dataArray[iter1];
	}
}

/* This function is used to print the array of numbers, to the console as output */
void printArray(int *dataArray, int countOfNumbers) {
	for (int iter1 = 0; iter1 < countOfNumbers; iter1=iter1+1)
	{
		cout << dataArray[iter1] << ";";
	}
}

/* Main driver function to follow through the code */
int main() {
	// necessary variables needed for program
	int countOfNumbers, *dataArray, indexed;
	cin >> countOfNumbers;
	dataArray=new int[countOfNumbers];
	takeInputNumbers(dataArray, countOfNumbers);
	indexed = countOfNumbers - 1;
	/* This code is based on sorting only, it heapify the current array
	and sorts the array on the max heap by calling the above function */
	int sizeOfHeap = indexed + 1;
	int iter1;
	for (iter1 = indexed / 2; iter1 >= 0; iter1 = iter1 - 1)
		heapifyAtMax(dataArray, indexed, iter1);
	for (iter1 = indexed; iter1 >= 1; iter1 = iter1 - 1) {
		swapValues(dataArray[0], dataArray[iter1]);
		sizeOfHeap = sizeOfHeap - 1;;
		heapifyAtMax(dataArray, sizeOfHeap, 0);
	}

	printArray(dataArray, countOfNumbers);
}
