// Lab10
// created by Jesus Vera
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/*GraphADT class*/
class GraphADT {
	/*graph vertices*/
	int totalVertices;
	vector<int>* graphEdges;
public:
	/*constructor of graph class*/
	GraphADT(int verts) {
		totalVertices = verts;
		graphEdges = new vector<int>[totalVertices];
	}

  /*function to help the depth first search on single node*/
  void utilityDepth(int countVertic, int *dataArray, int middlePoint, bool edgScenes[], vector<int>::iterator iter1, int firstID){
      if (graphEdges[countVertic].empty())
			dataArray[middlePoint] = countVertic;	
		  iter1=graphEdges[countVertic].begin();
		  while(iter1 != graphEdges[countVertic].end()) {
			  if (edgScenes[*iter1] == false) {
				  dataArray[*iter1] = middlePoint;
				  applyDepthFirstRec(edgScenes, *iter1, dataArray, middlePoint, firstID);
			  }
			iter1++;
		}
  }

	/*function to apply depth first search on graph*/
	void applyDepthFirstRec(bool edgScenes[], int countVertic, int* dataArray, int middlePoint, int firstID){
		edgScenes[countVertic] = true; 	 
		vector<int>::iterator iter1; 		
		
    utilityDepth(countVertic,dataArray,middlePoint,edgScenes,iter1,firstID);
    
    dataArray[middlePoint] = middlePoint;
	}
	/*function to insert the node into the graph*/
	void insertToNumSTck(int vertices, deque<int> &stack, bool edgScenes[]) {
		edgScenes[vertices] = true;   
		vector<int>::iterator iter1; 	
		iter1 = graphEdges[vertices].begin();
		while(iter1 != graphEdges[vertices].end()) {
			if(edgScenes[*iter1] == false) {
				insertToNumSTck(*iter1, stack, edgScenes); 
			}
			iter1++;
		}
		stack.push_front(vertices); 
	}
	/*function to add a new link to graph every time with two given vertices*/
	void insertNewLink(int u, int v) {
		graphEdges[v].push_back(u);	
	}
  /*print single node on graph*/
  void utilityPrint(int iter1, bool edgScenes[], deque<int> stack, GraphADT transposedGraph, int *dataArray, int vertNum){
    iter1=0;	
		while(iter1 < totalVertices) {
			edgScenes[iter1] = false;
			iter1++;			
		}		
		while (stack.empty() == false) {	
			int firstVertice = stack.front();
			stack.pop_front();
			if(edgScenes[firstVertice] == false) {
				transposedGraph.applyDepthFirstRec(edgScenes, firstVertice, dataArray, firstVertice, firstVertice);
			}
		}
    iter1=0;
		while(iter1 < vertNum) {
			cout << dataArray[iter1] << endl;
      iter1++;
		}
  }

	/*function to display graph with vertices*/
	void displayGraph(int vertNum) {
		int* dataArray = new int[vertNum];	
		int iter1,iter2;
		deque<int> stack;					
		bool* edgScenes = new bool[totalVertices];
		iter1=0;
		/*iterator through while to total vertices*/
		while(iter1 < totalVertices) {
			edgScenes[iter1] = false;	
			iter1++;			
		}		
		iter2=0;
		while(iter2 < totalVertices) {
			if (edgScenes[iter2] == false)			
				insertToNumSTck(iter2, stack, edgScenes);
			iter2++;
		}
		/*creating a new graph using constructor*/
		GraphADT tGraph(totalVertices);
		iter1=0;
		while(iter1 < totalVertices) {
			vector<int>::iterator j;
			for(j = graphEdges[iter1].begin(); j != graphEdges[iter1].end(); j++)
				tGraph.graphEdges[*j].push_back(iter1);  
			iter1++;
		} 

		  GraphADT transposedGraph = tGraph;	
			utilityPrint(iter1,edgScenes,stack,transposedGraph,dataArray,vertNum);
	}
};
/*helper function for input, used to take input and update the graph vertices*/
void takeInput(unsigned int edgeNum, GraphADT map, unsigned int firstVertice, unsigned int secondVertice)
{
  for (int iter1 = 0; iter1 < edgeNum; iter1++) {
		cin >> firstVertice >> secondVertice;
		map.insertNewLink(firstVertice, secondVertice);
	}
}
/*main driver function to run through the program*/
int main(int argc, const char * argv[]) {
	unsigned int edgeNum, vertNum, firstVertice, secondVertice;
	cin >> vertNum >> edgeNum;
	GraphADT map(vertNum);
	
  takeInput(edgeNum,map,firstVertice,secondVertice);

	map.displayGraph(vertNum);
	return 1;
}
