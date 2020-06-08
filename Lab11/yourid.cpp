// Lab11
// created by Jesus Vera
#include <iostream>
#include <limits.h>

using namespace std;

/*function to calculate the minimal tree within the given trees*/
void getLeastMSTREE(int data[], bool treeArray[], int nodeVertice) {
	int iter1 = 0;
	//looping against all vertices, assign a max value and print update each vertice
	while(iter1 < nodeVertice) {
		data[iter1] = INT_MAX;
		treeArray[iter1] = false;
		iter1++;
	}
	data[0] = 0;
}

/*function to find a node, which specifies the minimal resultant*/
void findMinTreeNodes(int &nodeVertice, int **graph, int &graphLinks, int &firstVert, int &secondVert, int &weight)
{
	int iter1 = 0;
	//initilaize the graph nodes on each vertice
	while (iter1 < nodeVertice) {
		int iter2 = 0;
		while (iter2 < nodeVertice) {
			graph[iter1][iter2] = 0;
			iter2++;
		}
		iter1++;
	}
	iter1 = 0;
	//update the graph links on each vertice
	while (iter1 < graphLinks) {
		cin >> firstVert;
		cin >> secondVert;
		cin >> weight;

		graph[firstVert][secondVert] = weight;
		graph[secondVert][firstVert] = weight;
		iter1++;
	}
}
/*function to find a path shortest between given vertices*/
void defineShortPath(int &nodeVertice, bool *treeArray, int *data, int **graph, int *leastWeight)
{
	int iter1 = 0;
	//find minimal index of node,
	//pass this node to loop
	//and fill all paths in graph matrix
	while (iter1 < nodeVertice - 1) {
		int fromVertice;
		int min_index = INT_MAX;
		int ind;
		int iter5 = 0;
		while (iter5 < nodeVertice) {
			if (treeArray[iter5] == false && data[iter5] < min_index) {
				min_index = data[iter5];
				ind = iter5;
			}
			iter5++;
		}
		fromVertice = ind;
		treeArray[fromVertice] = true;
		int iter2 = 0;
		while (iter2 < nodeVertice) {
			if (graph[fromVertice][iter2] && treeArray[iter2] == false && graph[fromVertice][iter2] < data[iter2]) {
				leastWeight[iter2] = fromVertice;
				data[iter2] = graph[fromVertice][iter2];
			}
			iter2++;
		}
		iter1++;
	}
}
/*function to run through the PMS algo, and get the short nodes*/
void PMSTreeAlgo(int nodeVertice, int graphLinks) {
	int firstVert, secondVert, weight;
	int **graph;
	graph = new int*[nodeVertice];
	int iter1 = 0;
	//loop over all vertices
	while (iter1 < nodeVertice)
	{
		graph[iter1] = new int[nodeVertice];
		iter1++;
	}
	//find the minimum tree nodes
	findMinTreeNodes(nodeVertice, graph, graphLinks, firstVert, secondVert, weight);

	int *leastWeight=new int[nodeVertice];
	int *data=new int[nodeVertice];
	bool *treeArray=new bool[nodeVertice];
	//update each tree node
	getLeastMSTREE(data, treeArray, nodeVertice);

	defineShortPath(nodeVertice, treeArray, data, graph, leastWeight);

	iter1 = 1;
	while (iter1 < nodeVertice) {
		cout << leastWeight[iter1] << endl;
		iter1++;
	}

}
/*main driver function*/
int main(int argc, char **argv) {
	int graphNodes = 1, graphLinks = 1;
	cin >> graphNodes>>graphLinks;
	PMSTreeAlgo(graphNodes, graphLinks);
}
