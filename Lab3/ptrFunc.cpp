#include <string>
#include <iostream>

using namespace std;

bool samedatatest(double *ptr1, double *ptr2);
bool sameaddresstest(double *ptr1, double *ptr2);
string booltostring(bool input); 
int main()
{

	double test = 5;
	double *ptr1 = &test;
	double *ptr2 = &test;
	cout << "Same data contained in both pointers ptr1 and ptr2: \t" 
		<< booltostring(samedatatest(ptr1, ptr2)) << endl;	
	cout << "Same address contained in both pointers ptr1 and ptr2: \t"
		<< booltostring(sameaddresstest(ptr1, ptr2)) << endl;
	
	//test area
	int ptrA = new int;
	int ptrB = new int;
	*ptrA = 345;
	ptrB = ptrA;
	
	
	return 0;
}

bool samedatatest(double *ptr1, double *ptr2)
{
	if(*ptr1 == *ptr2)
		return true;
	else return false;
}

bool sameaddresstest(double *ptr1, double *ptr2)
{
	if(&ptr1 == &ptr2)
		return true;
	else return false;	

}

string booltostring(bool input)
{
	if(input == 1)
		return("true");
	else 
		return("false");
}
