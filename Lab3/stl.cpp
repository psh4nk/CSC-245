#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;
void Initialize(vector<int>& v);
void Print(vector<int>& v);
void Reverse(vector<int>& v);
int main()
{
	stack<string> s1, s2;

	s1.push("Hi there");
	s2.push("H1 there");
	if(s1 == s2)
		cout << "s1 == s2" << endl;
	else if(s1 > s2)
		cout << "s1 > s2" << endl;
        else if(s1 < s2)
		cout << "s1 < s2" << endl;
	vector<int> v;
	Initialize(v);
	Print(v);
	Reverse(v);
	cout << "v reversed is: " << endl;
	Print(v);
	sort(v.begin(), v.end());
	cout << "v sorted is: " << endl;
	Print(v);
	return 0;
}

void Initialize(vector<int>& v)
{
	int a,b,c,d,e;
	cout << "Please enter five integers: ";
	cin >> a >> b >> c >> d >> e; 
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
}

void Print(vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)
		cout << "Element " << i << " of v is: " << v[i] << endl; 
}

void Reverse(vector<int>& v)
{
	reverse(v.begin(), v.end());
}
