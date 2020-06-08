
// Lab02
// Created by Jesus Vera on 02/04/2020.
// Copyright © 2020 UC Merced. All rights reserved.
#include <iostream>
//function for merge sort
void mergeSort(int elem[], int, int);
void combine(int elem[], int, int, int, int);
int main()
{
    int Item[999999]; //declaring array of elements to store values
    int Size, i; //this declares element size and a variable i
    std::cin >> Size; //this takes the input elements size
    
    //for loop for taking in elements
    for (i = 0; i < Size; i++)
    {
        std::cin >> Item[i]; //input line
    }
    //this calls in the function
    mergeSort(Item, 0, Size - 1); //this calls the function mergeSort
    //use this line to display the values
    for (i = 0; i < Size; i++) // for loop when i is less than Size
    {
        std::cout << Item[i] << ";";// used for the semicolon
    }
    return 0; //return values
}
//this function is applied to combine the elements of array
void combine(int Item[], int L, int LM, int RM, int R)
{
    //variables
    int x = L; int y = RM; int z = 0;
    int Array[999999]; //declaring an array for computation
    //merge sort algo
    while (x <= LM && y <= R)
    {
        if (Item[x] < Item[y]) //this if statement is used for to compare; first element is less than second element
        {
            Array[z++] = Item[x++];
        }
        else //this statement says that the second element is greater
        {
            Array[z++] = Item[y++]; }
    }
    
    //you have to repeat til xth index is not equal to LM
    while (x <= LM)
    {
        Array[z++] = Item[x++];}
    
    //you have to repeat until yth index is not equal to LM
    while (y <= R)
    {
        Array[z++] = Item[y++]; }
    //this is just copying elements to the original array.
    for (x = L, y = 0; x <= R; x++, y++)
    {
        Item[x] = Array[y];}
}
//this is the recursive function for merge sort to sort elements in the array.
void mergeSort(int Item[], int LEFT, int RIGHT) {
    //used to compare left and right side of array. to check if left is less than the right.
    if (LEFT < RIGHT){
        int MediumIndex = (LEFT + RIGHT) / 2; //obtaining the medium index
        mergeSort(Item, LEFT, MediumIndex); //begin sorting first half array
        mergeSort(Item, MediumIndex + 1, RIGHT); //finish sorting right half array
        combine(Item, LEFT, MediumIndex, MediumIndex + 1, RIGHT); } //combine/merge both arrays
}

