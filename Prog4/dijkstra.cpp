#include "queue.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "graph.h"
#include <cstdlib>
#include <sstream>
#include <vector>
#include <climits>
#include <iomanip>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

#include "SeparateChaining.h"


struct VertexType
{
	string name;
	bool marked;
	int distance;
	string previous;	
};

//void insertionSort(string cities[], int numVertices);
void checkInFile(int argc);
void buildDGraph(Graph<string> &dGraph, string filename, vector<string> &cities, int &numVertices, int &numEdges, VertexType myVertices[]);
void printCities(Graph<string> dGraph, int numVertices, VertexType myVertices[], vector<string> &cities);
string setStart(string start, int numVertices, VertexType myVertices[]);
void printRow(int location, VertexType myVertices[]);
int findMin(VertexType myVertices[], int numVertices);
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[]);
bool allMarked(int numVertices, VertexType myVertices[]);
void assignWeights(Graph<string> &dGraph, int numVertices, VertexType myVertices[], int startingLocation, Queue<string>& getTo);
int main(int argc, char* argv[])
{
	if(system("CLS")) system("clear");
	
	checkInFile(argc);	// Checks to see if Filename is given

	// Creation of Input File:
	string filename = argv[1];
	
	Graph<string> dGraph; 
	int numVertices = 0;
	int numEdges = 0;
	VertexType myVertices [50];
	vector<string> cities;
	buildDGraph(dGraph, filename, cities, numVertices, numEdges, myVertices);	// Builds the Graph using the data from the external file.
	printCities(dGraph, numVertices, myVertices, cities);	// Prints Cities found in file
	dijkstra(dGraph, numVertices, myVertices);	// Computes Dijkstra's Algorithm:
}

// Checks to see if Filename is given:
void checkInFile(int argc)
{
	if(argc == 0)
	{
		cerr << "The command line inputs were not correct.\nPlease try again.\n";
		exit(0);
	}
}

// Computes Dijkstra's Algorithm:
void dijkstra(Graph<string> &dGraph, int numVertices, VertexType myVertices[])
{
	string start;
	start = setStart(start, numVertices, myVertices);

	Queue<string> getTo(50);
	int startingLocation;
	for(int i = 0; i < numVertices; i++)
	{
		if(start == myVertices[i].name)
			startingLocation = i;
	}
	cout << "\n\n" << setw(14) << "Vertex" << setw(18) << "Distance" << setw(16) << "Previous\n\n";
	assignWeights(dGraph, numVertices, myVertices, startingLocation, getTo); 	
}

void assignWeights(Graph<string> &dGraph, int numVertices, VertexType myVertices[], int startingLocation, Queue<string>& getTo)
{
    myVertices[startingLocation].marked = true;
    myVertices[startingLocation].distance = 0;
    myVertices[startingLocation].previous = "N/A";
    printRow(startingLocation, myVertices);
    int prev, index;
    prev = startingLocation;

    while(!allMarked(numVertices, myVertices) && prev != -1)
    {
        dGraph.GetToVertices(myVertices[prev].name, getTo);
        while(!(getTo.isEmpty()))
        {
		for(int k = 0; k < numVertices; k++)
        	{
    	    		if(myVertices[k].name == getTo.getFront())
        		index = k;
        	}
       		if((!(myVertices[index].marked))&&(myVertices[index].distance > (dGraph.WeightIs(myVertices[prev].name, myVertices[index].name)+myVertices[prev].distance)))
        	{
            		myVertices[index].distance = dGraph.WeightIs(myVertices[prev].name, myVertices[index].name)+myVertices[prev].distance;
        		myVertices[index].previous = myVertices[prev].name;
    		}        
    		getTo.dequeue();
        }
        int minDistance = INT_MAX;
        int minIndex = -1;
        for(int i = 0; i < numVertices; i++)
        {
            if((myVertices[i].distance < minDistance)&&(!(myVertices[i].marked)))
            {
                minDistance = myVertices[i].distance;
                minIndex = i;
            }
        }
        prev = minIndex;
        myVertices[prev].marked = true;
	if(prev != -1)
        	printRow(prev, myVertices);
    }

    cout << "\n------------------------------------------------------------\n";
}

// Checks to see if all Vertices have been marked:
bool allMarked(int numVertices, VertexType myVertices[])
{
	int sum = 0;
	bool marked[numVertices];
	for(int i = 0; i < numVertices; i++)
	{
		if(myVertices[i].marked)
			marked[i] = true;	
	}
	
	for(int i = 0; i < numVertices-1; i++)
	{
		if(marked[i])
		{
			sum++;
		}
	}
	if(sum >= numVertices)
		return true;
	else 
		return false;
}

// Builds the Graph using the data from the External File:
void buildDGraph(Graph<string> &dGraph, string filename, vector<string> &cities, int &numVertices, int &numEdges, VertexType myVertices[])
{
	ifstream infile;
	infile.open(filename.c_str());
	if(!infile.is_open())
	{
		cerr << "File entered does not exist.\nPlease try again.\n";
		exit(0);
	}
	string city1, city2;
	int weight = 0;
	while(getline(infile, city1, ';'))
	// Insert cities from file into string array
	{
		getline(infile, city2, ';');
		infile >> weight;
		myVertices[numVertices].name = city1;
		myVertices[numVertices].marked = false;
		myVertices[numVertices].distance = INT_MAX;
		dGraph.AddVertex(city1);
		dGraph.AddVertex(city2);
		dGraph.AddEdge(city1, city2, weight);
		if(find(cities.begin(), cities.end(), city1) == cities.end())
			cities.push_back(city1);	
	 	if(find(cities.begin(), cities.end(), city2) == cities.end())
			cities.push_back(city2);
			
		infile.ignore(80, '\n');
		numVertices++;	
	}
	sort(cities.begin(), cities.begin() + cities.size()); 
}

// Prints Cities found in External File:
void printCities(Graph<string> dGraph, int numVertices, VertexType myVertices[], vector<string> &cities)
{
	int count = 0;
	cout << setw(14) << "----------------- DIJKSTRA'S ALGORITHM -------------------\n\n";
	cout << setw(14) << "A Weighted Graph Has Been Built For These " << cities.size() << " Cities : \n\n";
	for(int i = 0; i < cities.size(); i++)
	{
		
		count++;
		cout << setw(14) << cities.at(i); 
		if(count == 3)
		{
			cout << "\n";
			count = 0;
		}
	}
	cout << "\n\n";
}

// Finds the minimum non-marked values in VertexType Array:
int findMin(VertexType myVertices[], int numVertices)
{
 		int minWeight = INT_MAX - 1;
                int minThing = -1;
		for (int i = 0; i < numVertices; i++)
                {
                        if (myVertices[i].distance < minWeight && !myVertices[i].marked)
                        {
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }
			else if (myVertices[i].distance == minWeight && !myVertices[i].marked)
        		{
                                minWeight = myVertices[i].distance;
                                minThing = i;
                        }

		}        
		return minThing;
}

//Sets the Starting Value in Dijsktra's Algorithm:
string setStart(string start, int numVertices, VertexType myVertices[])
{
	cout << " Please input your starting vertex: ";
	string response;
	getline(cin,response);
	bool isThere = false;
	for (int i = 0;	i < numVertices; i++)
	{
		if (myVertices[i].name.compare(response) == 0)
		{
			start = response;
			return start;
		}
	}
	while (!isThere)
	{
		cout << " Starting location does not exist..." << endl;
		cout << " Please input your new vertex: ";
        	string response;
        	cin >> response;
		for (int i = 0; i < numVertices; i++)
        	{
                	if (myVertices[i].name.compare(response) == 0)
			{
                        	start = response;
                        	return start;
                	}
        	}
	}
}

// Prints a given row in a Summary Table:
void printRow(int location, VertexType myVertices[])
{
	if (myVertices[location].distance != -1)
	cout << setw(14) << myVertices[location].name << setw(18) << myVertices[location].distance << setw(16) << myVertices[location].previous << endl;
	else
	 cout << setw(14) << myVertices[location].name << setw(18) << "Not On Path" << setw(16) << myVertices[location].previous << endl;
}

