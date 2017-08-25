#include <queue>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int maxElemLength(const vector<int>& v);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
vector<int>QueuesToArray(vector<queue<int> >& QA, int numVals);
void RadixSort(vector<int>& L, int numDigits);
void PrintVector(const vector<int>& L);

int main()
{
	vector<int> L;			// the list to be sorted	
	L.push_back(380);
	L.push_back(95);
	L.push_back(345);
	L.push_back(382);
	L.push_back(260);
	L.push_back(100);
	L.push_back(492);
	cout << "Original array:\t\t";
       	PrintVector(L);
	RadixSort(L, maxElemLength(L));
	cout << "Radix sorted array:\t";
	PrintVector(L);
	return 0;
}

int maxElemLength(const vector<int>& v)
{
	// 1. returns the number of digits of
	// the largest integer within vector v
	int currmax = v[0];
	for(int i = 0; i < v.size(); i++)
		if(currmax < v[i])
			currmax = v[i];
	return  (currmax < 10 ? 1 :
		(currmax < 100 ? 2 :
		(currmax < 1000 ? 3 :
		(currmax < 10000 ? 4 :
		(currmax < 100000 ? 5 :
		(currmax < 1000000 ? 6 :
		(currmax < 10000000 ? 7 : 
		(currmax < 100000000 ? 8 :
		(currmax < 1000000000 ? 9 : 10 )))))))));

}

int GetDigit(int number, int k)
{
	// 2. Returns the kth digit of number
	return ((int)(number/pow(10, k-1)) % 10);

}

vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
{
	// 3. Creates and returns the intermediate
	// array of ten queues
 	vector<queue<int> > QA(10);
	for(int i = 0; i < L.size(); i++)
		if(GetDigit(L[i], k))
		{
			QA[GetDigit(L[i], k)].push(L[i]);	
		}
		else
		{
			QA[0].push(L[i]);
		}	
			
	return QA;	

}

vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
{
	// 4. Creates a new list from the values
	// in the intermediate array of queues
	vector<int> n(numVals);
	int pos = 0;
	for(int i = 0; i < QA.size(); i++)
		while(!QA[i].empty())
		{
			n[pos] = QA[i].front();
			QA[i].pop();
			pos++;
		}
	return n;

}
void RadixSort(vector<int>& L, int numDigits)
{
	// 5. Implements the radix sort, 
	// calling ItemsToQueue and QueuesToArray
	int max = maxElemLength(L);
	vector<queue<int> > QA(10);
	for(int i = 0; i <= max; i++)
	{
		QA = ItemsToQueues(L, i);
		L = QueuesToArray(QA, L.size());
	}	
	
}

void PrintVector(const vector<int>& L)
{
	// 6. Prints out the contents of the
	// vector parameter without modifying
	// it in any way
	for(int i = 0; i < L.size(); i++)
	{
		cout << L[i] << " ";
	}

	cout << "\n";
}
