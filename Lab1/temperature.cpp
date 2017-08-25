//Preston Shankle
//CSC 245
//Temperature program -- takes in temperature in Celsius and returns the value in Fahrenheit.

#include <iostream>
using namespace std;

double convert (double value);

int main ()
{
	double tmp = 0;
	cout << "Please enter a Celsius value: ";
	cin >> tmp;
	cout << tmp << " degrees Celsius is " << convert(tmp) << " degrees Fahrenheit." << endl;
	return 0;
}

double convert (double tmp)
{
	double newtmp = 1.8 * tmp + 32.0;	
	return newtmp;	
}
