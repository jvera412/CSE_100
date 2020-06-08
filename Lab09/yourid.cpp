// Lab09
// created by Jesus Vera
#include<iostream>
#include <vector>
#include<map>
#include<queue>
#include<string>
using namespace std;

/*
* map of charcters to store the character counts
*/
map<char, string> charactersMap;
struct  CharacterNode {
	char character;
	double mainFrequency;
	CharacterNode* nodeOnLeft;
	CharacterNode* nodeOnRight;
};
/*
* inner structure to calculate over the left and right nodes of the compared
* and return true and false accordingly
*/
struct nodeComparison {
	bool operator()(CharacterNode* nodeOnLeft, CharacterNode* nodeOnRight) {
		if (nodeOnLeft->mainFrequency > nodeOnRight->mainFrequency)
			return true;
		else
			return false;
	}
};
/*
* data queue to push all the results into
*/
priority_queue<CharacterNode *, vector<CharacterNode *>, nodeComparison> dataQueue;
CharacterNode* createNewNode(char character, double mainFrequency) {
	CharacterNode* createNewNode = new CharacterNode();
	createNewNode->mainFrequency = mainFrequency;
	createNewNode->character = character;
	createNewNode->nodeOnLeft = NULL;
	createNewNode->nodeOnRight = NULL;
	return createNewNode;
}
/*
* function to create and start an empty node
*/
CharacterNode* creatEmptyNode() {
	CharacterNode* newNodeTemp = new CharacterNode();
	newNodeTemp->nodeOnLeft = NULL;
	newNodeTemp->nodeOnRight = NULL;
	newNodeTemp->character = '\0';
	newNodeTemp->mainFrequency = 0.0;
	return newNodeTemp;
}
/*
* function to create a new data array, and apply the above functions on this array
*/
static void encryptCharacterQueue(CharacterNode *dataQueue, string coded, int iter1) {
	char arrayOfCharacters[] = { 'A','B','C','D','E','F' };
	if (dataQueue == NULL)
		return;
	if (dataQueue->character == arrayOfCharacters[iter1])
		charactersMap.insert(make_pair(arrayOfCharacters[iter1], coded));
	if (dataQueue->character != arrayOfCharacters[iter1]) {
		encryptCharacterQueue(dataQueue->nodeOnLeft, coded + "0", iter1);
		encryptCharacterQueue(dataQueue->nodeOnRight, coded + "1", iter1);
	}
}
/*
* function to be called by uff function, this takes in all the queues and get the tops of queues
* checks which one is a huff and then loops from index 6 to first to print the nodes
*/
void expandHuffNode(CharacterNode *firstQueue, CharacterNode *secondQueue, CharacterNode *thirdQueue)
{
	int iter2 = 6;
	while (iter2 != 1) {
		firstQueue = dataQueue.top();
		dataQueue.pop();
		secondQueue = dataQueue.top();
		dataQueue.pop();
		thirdQueue = createNewNode(' ', (firstQueue->mainFrequency + secondQueue->mainFrequency));
		thirdQueue->nodeOnLeft = firstQueue;
		thirdQueue->nodeOnRight = secondQueue;
		dataQueue.push(thirdQueue);
		iter2--;
	}
}
/*
* function to make the huff tree, first it creates 3 nodes
* then it makes a list of huff nodes by above function and then finally it calls the encrypt character function
* to encrypt and then print that node results
*/
void makeHuffTree() {
	CharacterNode *firstQueue = creatEmptyNode();
	CharacterNode *secondQueue = creatEmptyNode();
	CharacterNode *thirdQueue = creatEmptyNode();
	expandHuffNode(firstQueue, secondQueue, thirdQueue);
	int iter1 = 0;
	while(iter1 < 6) {
		encryptCharacterQueue(dataQueue.top(), "", iter1);
		iter1++;
	}
}
/*
* function to take an array and initialize it with the characters from array
* that are A to F
*/
void initializeQueueArray(int &firstQueue, double &mainFrequency)
{
	while (firstQueue != 6) {
		cin >> mainFrequency;
		if (firstQueue == 0)
			dataQueue.push(createNewNode('A', mainFrequency));
		if (firstQueue == 1)
			dataQueue.push(createNewNode('B', mainFrequency));
		if (firstQueue == 2)
			dataQueue.push(createNewNode('C', mainFrequency));
		if (firstQueue == 3)
			dataQueue.push(createNewNode('D', mainFrequency));
		if (firstQueue == 4)
			dataQueue.push(createNewNode('E', mainFrequency));
		if (firstQueue == 5)
			dataQueue.push(createNewNode('F', mainFrequency));
		firstQueue++;
	}
}
/*
* main driver function to call above functions to make the huffmans
*/
int main() {
	double mainFrequency;
	int firstQueue = 0;
	initializeQueueArray(firstQueue, mainFrequency);
	makeHuffTree();
	map<char, string>::iterator iter3 = charactersMap.begin();
	while (iter3 != charactersMap.end()) {
		cout << iter3->first << ":" << iter3->second << std::endl;
		iter3++;
	}
}
