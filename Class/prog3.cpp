#include <iostream>
using namespace std; // namespace where cin & cout are declared

void printMe();	     // Function Prototype ("Declaration")
		     // Note: All Prototypes go prior to main 
		     // they are just function header with a semicolon attached

int main(){
	printMe();
	return 0;
}

void printMe(){
	cout << "Hello World!" << endl;
}
