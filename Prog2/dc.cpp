#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <math.h>
#include "stack.h"

using namespace std;

void optionSwitch(char& c, Stack<int>& s);
void printStack(Stack<int>& s);
bool isOperator(char& c);
int operationSwitch(int& num1, int& num2, char& c, Stack<int>& s);
void stringParser(string& input, Stack<int>& s);

int main()
{
	Stack<int> s;
	string input;
	while(true)
	{
		getline(cin, input);
		try
		{
			stringParser(input, s);
		}
		catch (Underflow exc)
		{
			cout << "dc: stack empty" << endl;
		}
		catch (Overflow exc)
		{
			cout << "dc: stack full" << endl;
		}
	}
	return 0;
}

void optionSwitch(char& c, Stack<int>& s)
{
	// pre: a char c has been initialized with data from the
	//      user
	// post: one of the 6 cases has been used to perform a 
	// 	 function on the stack 
	switch(c)
	{
		case 'p':
			std::cout << s.top() << endl;
			break;
		case 'n':
			std::cout << s.topAndPop();
			break;
		case 'f':
			printStack(s);  
			break;
		case 'c':
			s.makeEmpty();
			break;
		case 'd':
			int temp; 
			temp = s.top();
			s.push(temp);
			break;
		case 'r':
			int top1, top2;
			top1 = s.topAndPop();
			top2 = s.topAndPop();
			s.push(top1);
			s.push(top2);
			break;
		default:
			break;
	}	// end switch
}

void printStack(Stack<int>& s)
{
	// pre:  a stack has been pushed on to with data from the 
	//       user
	// post: the stack is printed to the console, separated 
	// 	 by lines
	Stack<int> temp = s;
	while(!temp.isEmpty())
		cout << temp.topAndPop() << "\n";
}

bool isOperator(char& c)
{
	// pre: char c has been initialized with data from the user
	// post: a boolean is returned determining whether
	// 	 char array c contains one of the operator characters
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
		return true;
	else 
		return false;
}

bool isOption(char& c)
{
	// pre: char c has been initialized with data from the user
	// post: a boolean is returned determining whether 
	//       char array c contains one of the option characters
	if(c == 'p' || c == 'n' || c == 'f' || c == 'c' || c == 'd' || c == 'r')
		return true;
	else 
		return false;
}

int operationSwitch(int& num1, int& num2, char& c, Stack<int>& s)
{
	// pre: num1, num2, and char c have all been initialized 
	// 	with data from the input string
	// post: a new result from one of the 5 calculations
	// 	 has been pushed to the stack
	int result = 0;
	try
	{
	switch (c)
	{
		case '+':
			result = num2 + num1;
			break;
		case '-':
			result = num2 - num1;
			break;
		case '*':
			result = num2 * num1;
			break;
		case '/': 
			if(num1 != 0)
				result = num2 / num1;
			else
				cout << "Integer division by zero not allowed.\n";
				
			break;
		case '%':
			if(num1 != 0)
				result = num2 % num1;
			else
				cout << "Integer division by zero not allowed.\n";
			break;
		case '^':
			result = pow(num2, num1);
			break;
		default:
			break;
	}
	}
	catch (DivisionByZero exc)
	{
		cout << "Integer division by zero not allowed.\n";
	}
	return result;
}

void stringParser(string& input, Stack<int>& s)
{
	// pre: input has been initialized with input from the user
	// post: calculator has been ran by the user and all desired functions
	//	have been used.

	char *c = new char[input.size() + 1];
	memcpy(c,input.c_str(), input.size());
	int j = 0;
	int l = 0;
	int k, num1, num2;
	bool makenegative = false;
	string currint;
	bool skip = false;
	try
	{
	for(int i = 0; i < input.length(); i++)
	{
		currint = "";
		if(c[j] == '_'){
			makenegative = true;
			j++;
		}
		if(c[j] == ' '){
			j++;
		}
		while(isdigit(c[j]))
		{
			ostringstream oss;
			oss << c[j];
			currint += oss.str();
			j++;
			l++;
			skip = true;
		}
		if(l > 0)
		{
			int k = atoi(currint.c_str());
			if (makenegative)
				k = -k;
			s.push(k);
			l = 0;
			makenegative = false;
			skip = true;
		}
		else if(isOption(c[j]))
		{
			optionSwitch(c[j], s);
			currint = "";
			j++;
			l = 0;	
			skip = false;
		}

		else if(isOperator(c[j]))
		{
			num1 = s.topAndPop();
			num2 = s.topAndPop();
			int result = (operationSwitch(num1, num2, c[j], s));
			s.push(result);
			
			if((c[j] == '/' || c[j] == '%') && num1 == 0)
				s.pop();	
			
			currint = "";
			j++;
			l = 0;
			skip = false;
		}
		else if(!isOperator(c[j]) && !isOption(c[j]) && !isdigit(c[j]) && !skip)
		{
			cout << "'" <<  c[j] << "' unimplemented\n";
			currint = "";
			j++;
			l = 0;
			skip = false;
		}
	}
	}
	catch(DataError exc)
	{
		cout << "'" <<  c[j] << "' unimplemented\n";
	}
}
