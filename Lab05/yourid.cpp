
//  Lab05
//  Created by Jesus Vera
//  Copyright © 2020 UC Merced. All rights reserved.
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;


//functions prototype is here
void STABLE_COUNT_SORT(vector<int> rdArray[], int , int);
void RADIX_SORT(vector<int> rdArray[], int);

int main()
{
    //declaring the proper variables
    int total_size;
    cin >> total_size;    //taking input total values
    vector<int>* vectorArray;    //declaring array of vectors
    
    vectorArray = new vector<int>[total_size];
    
    //taking input in for total size
    for (int i = 0; i < total_size; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            int n;
            cin >> n;
            vectorArray[i].push_back(n);//values into array
        }
    }
    
    //applying the function
    RADIX_SORT(vectorArray, total_size);
    
    //displaying the values
    for (int i = 0; i < total_size; i++)
    {
        for (vector<int>::iterator iter = vectorArray[i].begin(); iter != vectorArray[i].end(); iter++)
        {
            cout << *iter << ";";
        }
        cout << endl;
    }
    
    return 0;
}



//Implementation of funcion 'STABLE_COUNT_SORT'
void STABLE_COUNT_SORT(vector<int> rdArray[], int left, int right)
{
    
    //creating the vectors
    vector<int>* vectors = new vector<int>[left];
    int i = 0;
    
    //starts the array with 0
    int stableCountArr[10] = { 0 };
    
    
    //updating the array values
    for (i = 0; i < left; i++)
    {
        stableCountArr[rdArray[i][right] % 10]++;
    }
    
    for (i = 1; i < 10; i++)
    {
        stableCountArr[i] += stableCountArr[i - 1];
    }
    
    for (i = left - 1; i >= 0; i--)
    {
        //updates the array
        vectors[stableCountArr[rdArray[i][right] % 10] - 1] = rdArray[i];
        stableCountArr[rdArray[i][right] % 10]--;
    }
    for (i = 0; i < left; i++)
    {
        rdArray[i] = vectors[i]; //stores values
    }
}

//Implementation of function 'RADIX_SORT'
void RADIX_SORT(vector<int> rdArray[], int value)
{
    for (int p = 9; p >= 0; p--)
    {
        STABLE_COUNT_SORT(rdArray, value, p); //calling function STABLE_COUNT_SORT
    }
}
