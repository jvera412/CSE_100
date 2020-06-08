//  Lab12
//  Created by Jesus Vera
#include <iostream>
#include <limits.h>
using namespace std;
//Functions used in this code

void initialization(int* d, int numberOfVerixes);
void updatedGraph(int** graph, int* d, int numberOfVerixes, int numberOfEdges);
void display(int* d, int numberOfVerixes);
void BellmanFordAlgraphorithm(int** graph, int numberOfVerixes, int numberOfEdges);
//main driver function
int main()
{
    //this is declaring  and initialize appropriate variables
    int index = 0;
    int numberOfVertex = 0;
    int numberOfEdges = 0;
    int edge = 0;
    int vertex = 0;
    int weight = 0;
    cin >> numberOfVertex;
    cin >> numberOfEdges;
    int** graph; //2d graph
    graph = new int* [3]; //creating graph
    //initialize graph indexes
    while (index < numberOfVertex)
        
    {
        graph[index] = new int[numberOfEdges];
        index++;
    }
    index = 0;
    while (index < numberOfEdges)    //while index is less than number of edges
    {
        //taking input edge, vertex and weight
        cin >> edge >> vertex >> weight;
        graph[0][index] = edge;
        graph[1][index] = vertex;
        graph[2][index] = weight;
        index = index + 1;
    }
    BellmanFordAlgraphorithm(graph, numberOfVertex, numberOfEdges);        //calling algorithm function
    return 0;
}
//Implementation of function 'initialization'
void initialization(int* dist, int numberOfVertex)
{
    for (int i = 0; i < numberOfVertex; i++)
    {
        dist[i] = INT_MAX;//initialize each index to max
    }
    dist[0] = 0;
}
//Implementation of function 'updatedGraph'

void updatedGraph(int** graph, int* d, int numberOfVerixes, int numberOfEdges)

{
    //declaring the variables
    int u, v, w;
    //loop from 1 to number of vertixes
    for (int i = 1; i < numberOfVerixes; i++)
    {
        //loop from 1 to number of edges
        for (int j = 0; j < numberOfEdges; j++)
        {
            u = graph[0][j];
            v = graph[1][j];
            w = graph[2][j];
            if (d[u] != INT_MAX)    //if d[u] is not max
            {
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;//updated values
                    
                }  } }
    }}

//Implementation of function 'display'

void display(int* dist, int numberOfVerixes)

{
    
    cout << "TRUE" << endl;
    
    for (int i = 0; i < numberOfVerixes; i++)
        
    {
        
        //if dist[i] is less than max
        
        if (dist[i] < INT_MAX)
            
            cout << dist[i] << endl;
        
        if (dist[i] == INT_MAX)        //if dist[i] is equal to the max
            
            cout << "INFINITY" << endl;
        
    }
    
}
//Implementation of function 'BellmanFordAlgraphorithm'

void BellmanFordAlgraphorithm(int** graph, int numberOfVerixes, int numberOfEdges)

{
    int condition = 1;
    
    int dist[numberOfVerixes];
    
    int u, v, w;
    //for each vertex V in graph
    
    initialization(dist, numberOfVerixes);
    
    //calling function 'updated graph'
    
    updatedGraph(graph, dist, numberOfVerixes, numberOfEdges);
    
    for (int j = 0; j < numberOfEdges; j++)
        
    {
        
        //get edge, vertex and weight
        
        u = graph[0][j];
        
        v = graph[1][j];
        
        w = graph[2][j];
        
        //if distance of edge is not max
        
        if (dist[u] != INT_MAX)
        {
            if (dist[graph[1][j]] > dist[graph[0][j]] + graph[2][j])
                condition = 2;
        }
    }
    //check condition
    
    switch (condition)
    {
        case 1:
            display(dist, numberOfVerixes);    //calling function 'display'
            break;
        case 2:
            cout << "FALSE" << endl;//display false
            break;
        default:
            NULL;
            
    }
    
}

