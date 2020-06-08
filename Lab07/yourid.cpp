//  Lab07
//  Created by Jesus Vera 
//  Copyright © 2020 UC Merced. All rights reserved.

#include <iostream>

using namespace std;



/*
 
 * The following is a helping method
 
 * this methods takes in the original numbers array
 
 * it starts reading the array and keeps updating every second index in the array
 
 * looping over double times, in n^2 complexity... this updates until the last index
 
 * of the array is kept following and finally returns the modified array
 
 */

void updateIndexes(int arrayOfLengths[], int totalValue, int arrayRange1[], int arrayRange2[]) {
    
    arrayRange1[0] = 0;
    
    int iter2 = 1;
    
    while (iter2 <= totalValue) {
        
        int tempVal = 0;
        
        int iter1 = 1;
        
        while (iter1 <= iter2) {
            
            if (tempVal < arrayOfLengths[iter1] + arrayRange1[iter2 - iter1]) {
                
                tempVal = arrayOfLengths[iter1] + arrayRange1[iter2 - iter1];
                
                arrayRange2[iter2] = iter1;
                
            }
            
            iter1++;
            
        }
        
        arrayRange1[iter2] = tempVal;
        
        iter2++;
        
    }
    
}



/*
 
 * This is the main road cutting algorithm, this algorithm is called from main method
 
 * and then it is used in calling the helper method to update the whole array of numbers
 
 * it updates the actual array by making the halves of the array at every index
 
 * and then returns the modified array to the main
 
 */

int RoadCuttingAlgo(int arrayOfLengths[], int totalValue) {
    
    
    
    int *arrayRange1=new int[totalValue + 1];
    
    int *arrayRange2=new int[totalValue + 1];
    
    
    
    updateIndexes(arrayOfLengths, totalValue, arrayRange1, arrayRange2);
    
    
    
    cout << arrayRange1[totalValue] << endl;
    
    while (totalValue>0) {
        
        cout << arrayRange2[totalValue] << " ";
        
        totalValue = totalValue - arrayRange2[totalValue];
        
    }
    
    return -1;
    
}



/*
 
 * This method is used to Take input of the whole numbers
 
 * Take the whole numbers, makes the array initialized and then
 
 * fill the whole array and return it
 
 */

void takeInput(int inputArray[], int numberOfValues) {
    
    inputArray[0] = 0;
    
    for (int iter1 = 1; iter1<numberOfValues + 1; iter1++) {
        
        cin >> inputArray[iter1];
        
    }
    
}



/*
 
 * This method is used to print the results to screen
 
 */

void printResults(int value) {
    
    cout << value << endl;
    
}



/*
 
 * This is main method, it declares the array and its variables,
 
 * it fills the array and then returns the values
 
 */

int main() {
    
    int numberOfValues;
    
    cin >> numberOfValues;
    
    int *arrayOfLengths=new int[numberOfValues + 1];
    
    arrayOfLengths[0] = 0;
    
    takeInput(arrayOfLengths, numberOfValues);
    
    
    
    int resultantReturn = RoadCuttingAlgo(arrayOfLengths, numberOfValues);
    
    printResults(resultantReturn);
    
    
    
    return 0;
    
}


