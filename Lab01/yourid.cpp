// Lab01: Insertion Sort
// created by Jesus Vera on 01/27/2020
#include <iostream>

/*
* the following function swaps the values of two
* given variables, the references of the variables
* are passed here so values are swapped by each other
* on the given aliases
*/
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

/*
* the following is a general function that simply prints 
* the given array that is passed to it according to the
* size of the array passed to it in a specified format
*/
void printArray(int *numberList, int size)
{
    for(int iter2 = 0; iter2 <= size; ++iter2) { 
        std::cout << numberList[iter2] << ";";
    }
    std::cout << std::endl;
}

/*
* this is the main driver function, this function first
* takes input the number of values, then inputs all the values
* loops over the array and matches every adjacent value, if the
* next value is lesser than the previous value, it calls the function
* swap() to swap these two values
* on the end of two loops all the values are being sorted well
* then it calls the print function to display the results on the screen
*/
int main()
{
    int totalNumbers;
    int numberList[999999];
    int counter = 1; 
    std::cin >> totalNumbers;
    for(int number = 0; number < totalNumbers; ++number)
        std::cin >> numberList[number]; 
    int n = totalNumbers; 
    //psuedocode from Introduction to Algorithms: Third Edition; Insertion Sort
    //following loop gets through all the numbers that are inputted
    for (int iter1 = 1; iter1 < totalNumbers; iter1++) { 
        //matches each of the number with its previous number
        for(int iter2 = iter1; iter2 > 0; iter2--)
            if(numberList[iter2] < numberList[iter2-1]) { 
                //if the previous number is greater than it, it swaps both of the numbers
                swap(numberList[iter2], numberList[iter2-1]);
                //increments the counter of the loop, to check if there was a swap or not
                counter++;
            }
        printArray(numberList,iter1);
    }
    return 0; 
}
