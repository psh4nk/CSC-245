//Created by Preston Shankle
//CSC 245
//3-21-2017

#include <queue>
#include <iostream>
#include <string>

void insertContents(std::priority_queue<std::string>& pq);
void printContents(std::priority_queue<std::string>& pq);
int main()
{
	std::priority_queue<std::string> pq;
	insertContents(pq);
	printContents(pq);	
	return 0;
}

void insertContents(std::priority_queue<std::string>& pq)
{
	pq.push("Fili");
	pq.push("Kili");
	pq.push("Balin");
	pq.push("Dwalin");
	pq.push("Oin");
	pq.push("Gloin");
	pq.push("Dori");
	pq.push("Ori");
	pq.push("Nori");
	pq.push("Bifur");
}


void printContents(std::priority_queue<std::string>& pq)
{
	std::cout << "Contents of priority queue: ";
	while(!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();		
	}
	std::cout << "\n";
}
