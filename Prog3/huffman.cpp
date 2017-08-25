#include "huffman.h"
#include <iostream>
#include <queue>
using namespace std;

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}

void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, -1, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;
}

bool HuffmanTree:: inTree(char ch) {
	return (lookUp(ch) != -1);
}

int HuffmanTree:: GetFrequency(char ch) {
	return GetFrequency(lookUp(ch));
}

int HuffmanTree:: GetFrequency(int i) {
	return nodes[i].weight;		
}

char HuffmanTree:: GetChar(int i){
	return nodes[i].ch;
}

int HuffmanTree:: GetNumChars(){
	return numChars;
}

int HuffmanTree:: lookUp(char ch) {
	int index = -1;
	for(int i = 0; i < nodes.size() - 1; i++)
	{
		if(nodes[i].ch == ch)
		{	
			index = i;
		}
	}
	return index;
}

string HuffmanTree:: GetCode(char ch) {
	return GetCode(lookUp(ch));	
}


string HuffmanTree:: GetCode(int i) {
 	 if (nodes[i].parent == 0)
           return "";
      	 else
            return (GetCode(nodes[i].parent) + (char)(nodes[i].childType+'0'));
}

void HuffmanTree:: PrintTable() {
	int tcounter = 1;
	cout << "\t\t++++ ENCODING TABLE ++++\t\n\n";
	cout << "\tIndex\tChar\tWeight\tParent\tChildType\n";
	for(int i = 0; i < numChars * 2 - 1; i++)
		if(nodes[i].ch != '\n' && nodes[i].ch != ' ' && nodes[i].ch)
			cout << '\t' << i << "\t" << nodes[i].ch << "\t" << nodes[i].weight << "\t" << nodes[i].parent << "\t" << nodes[i].childType << "\n";
		else if(nodes[i].ch == '\n')
			cout << '\t' << i << "\tnl\t" << nodes[i].weight << "\t" << nodes[i].parent << "\t" << nodes[i].childType << "\n";
		else if(nodes[i].ch == ' ')
			cout << '\t' << i << "\tsp\t" << nodes[i].weight << "\t" << nodes[i].parent << "\t" << nodes[i].childType << "\n";
		else if(i != numChars*2-2)
		{
			cout << '\t' << i << "\tT" << tcounter << "\t" << nodes[i].weight << "\t" << nodes[i].parent << "\t" << nodes[i].childType << "\n";
			tcounter++;
		}
		else
                       cout << '\t' << i << "\tT" << tcounter << "\t" << nodes[i].weight << "\t0\tN/A\n";

}

int HuffmanTree:: numNodes() {
	return numChars*2-1;

}

void HuffmanTree:: build() {
	for(int j = 0; j < numChars* 2 - 1; j++)
	{
		if(getSmaller(j) != -1 && ((nodes[j].parent == -1 || nodes[getSmaller(j)].parent == -1)))
		{
			HNode newNode = {'\0', nodes[j].weight + nodes[getSmaller(j)].weight, -1, -1};
			nodes.push_back(newNode);
			nodes[j].parent = nodes.size() - 1;
			nodes[getSmaller(j)].parent = nodes.size() - 1;
			j++;
			if(getSmaller(j) != -1)
   		        {
				nodes[j].parent = nodes.size() - 1;
				nodes[getSmaller(j)].parent = nodes.size() - 1;
			}
		}
	}
	for(int i = 0; i < nodes.size() - 1; i++)
	{
		nodes[i].childType = 0;
		i++;
		nodes[i].childType = 1;
	}
	nodes[nodes.size() - 1].parent = 0;
	nodes[nodes.size() - 1].childType = -1;
}

int HuffmanTree:: getSmaller(int compare){
	int result = -1;
	for(int i = 0; i < nodes.size() - 1; i++)
		if(nodes[i].weight <= nodes[compare].weight && i != compare)	
			result = i;
	return result;
}
