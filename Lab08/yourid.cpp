// Lab08
// Created by Jesus Vera
// Copyright © 2020 UC Merced. All rights reserved.
#include <climits>
#include <iostream>
#include <deque>
using namespace std;

/*
 * The following function is used to use the recursion to print the
 * styles array that includes in brackets formatting just like (((a)b(c)))
 */
void FormatOutput(deque<deque<int > >&s, int iter1, int iter2){
    if(iter1==iter2){
        cout <<"A"<<(iter1-1);
        return;
    }
    else
        cout<< "(";
    FormatOutput(s, iter1, s[iter1][iter2]);
    FormatOutput(s, s[iter1][iter2]+1, iter2);
    cout<<")";
}

/*
 * The following program works on the ROWS of given passed matrix to iter1
 * generates a 2D matrix and fill the matrix value by using the matrix multiply formula
 * it fills a 2D array and fills a vector of array to print the result of matrix then
 */
void displayPoints(int ROWS, int **inputMatrix, int dataArray[], deque<deque<int>> &s)
{
    int l=2;
    while(l<=ROWS){
        int iter1=1;
        while(iter1<=ROWS-l+1){
            int  iter2=iter1+l-1;
            inputMatrix[iter1][iter2] = INT_MAX;
            int iter3=iter1;
            while(iter3<=iter2-1){
                int q = inputMatrix[iter1][iter3]+inputMatrix[iter3+1][iter2]+dataArray[iter1-1]*dataArray[iter3]*dataArray[iter2];
                if(q < inputMatrix[iter1][iter2]){
                    inputMatrix[iter1][iter2]=q;
                    s[iter1][iter2]=iter3;
                }
                iter3++;
            }
            iter1++;
        }
        l++;
    }
}

/*
 * The following function is called by the main method, it is used
 * to create 2d matrix
 * call the above function to take input into matrix
 * then build 2d arrays and a qeueu and calcualte the results
 * then this function calls the output function and prints the values to screen
 */
void multiplyMat(int dataArray[], int ROWS){
    ROWS=ROWS-1;
    deque<deque<int> >s;
    s.resize(ROWS+1, deque<int>(ROWS+1,0));
    int **inputMatrix;
    inputMatrix=new int*[ROWS+1];
    for(int temp=0;temp<(ROWS+1);temp++)
    {
        inputMatrix[temp]=new int[ROWS+1];
    }
    int iter1,iter2;
    iter1=1;
    while(iter1 <= ROWS){
        inputMatrix[iter1][iter1]=0;
        iter1++;
    }
    
    displayPoints(ROWS,inputMatrix,dataArray,s);
    
    cout << inputMatrix[1][ROWS]<< endl;
    FormatOutput(s,1,ROWS);
    cout <<endl;
}

/*
 * This function is used to take input from the users
 */
void takeInput(int count, int dataArray[])
{
    for(int iter1 =0; iter1 <count+1; iter1++){
        cin>> dataArray[iter1];
    }
}

/*
 * This is the main function used to call the above function to move through the program
 */
int main(){
    int count;
    cin>>count;
    int dataArray[count+1];
    takeInput(count,dataArray);
    multiplyMat(dataArray, count+1);
}
