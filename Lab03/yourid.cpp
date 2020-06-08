// Lab03
// Created by Jesus Vera on 02/13/2020.
// Copyright © 2020 UC Merced. All rights reserved.
#include <iostream>

using namespace std;

/*The following mathod returns the maximum of the integers*/
int getMax() {
	return INT_MAX;
}
/*The following method returns the minimum of the integers*/
int getMin() {
	return INT_MIN;
}
/*The following method gets the array, and gets the index of array to iterate
it starts iterating over the array and then gets the sum of those indexes, this sum
is returned to the main where it is called*/
int getSumArray(int index1, int index2, int *numberArray, int totalSum, int firstArraySum) {
	int iter1;
	
	for (iter1 = index1; iter1 >= index2; iter1--) {
		totalSum += numberArray[iter1];
		if (totalSum > firstArraySum)
			firstArraySum = totalSum;
	}
	return firstArraySum;
}
/*The following mathod gets the array and its indexes
this iterates in the diagonal cross and find the value at diagonal method
the cross of the sum is calculated and returned*/
int findSubArrayWithCrossSum(int numberArray[], int startingIndex, int middleIndex, int endingIndex) {
	int firstArraySum = getMin();
	int totalSum = 0, largestValueOnLeft, largestValueOnRight, maxRight;
	int iter2;

	firstArraySum = getSumArray(middleIndex, startingIndex, numberArray, totalSum, firstArraySum);

	largestValueOnRight = getMin(); 
	totalSum = 0;

	for (iter2 = middleIndex + 1; iter2 <= endingIndex; iter2++) {
		totalSum += numberArray[iter2];
		if (totalSum > largestValueOnRight)
			largestValueOnRight = totalSum;
	}
	return firstArraySum + largestValueOnRight;
}
/*The following method returns a part of the array of the full array
whichever gives the sum maximum of all*/
int getSubArrayWithMaxSum(int numberArray[], int startingIndex, int endingIndex) {
	int middleIndex, firstArraySum, largestValueOnRight, crossSum;
	if (endingIndex == startingIndex)
		return numberArray[startingIndex]; 
	else {
		middleIndex = (startingIndex + endingIndex) / 2;
		firstArraySum = getSubArrayWithMaxSum(numberArray, startingIndex, middleIndex);
		largestValueOnRight = getSubArrayWithMaxSum(numberArray, middleIndex + 1, endingIndex);
		crossSum = findSubArrayWithCrossSum(numberArray, startingIndex, middleIndex, endingIndex);
		if (firstArraySum >= largestValueOnRight && firstArraySum >= crossSum)
				return firstArraySum;
		else if (largestValueOnRight >= firstArraySum && largestValueOnRight >= crossSum) 
			return largestValueOnRight;
		else
			return crossSum;
	}
}
/*The following method inputs all the array*/
void userInputArray(int *numberArray, int n) {
	for (int iter1 = 0; iter1 < n; iter1++) {
		cin >> numberArray[iter1];
	}
}
/*Main program*/
int main() {
	int numberOfInputs, maximumArraySum;
	cin >> numberOfInputs;
	int *numberArray=new int[numberOfInputs];
	userInputArray(numberArray, numberOfInputs);
	maximumArraySum = getSubArrayWithMaxSum(numberArray, 0, numberOfInputs - 1);
	cout << maximumArraySum;
}
