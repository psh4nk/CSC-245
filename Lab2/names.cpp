
#include <string>
#include <iostream>
using namespace std;

void BreakDown (string name, string& first, string& last, string& mi);
void getdate (string date, string& month, string& day, string& year);
int main()
{
	string name, first, last, mi;
	string date, month, day, year;
	cout << "Name? <Last, First MI.> ";
	getline (cin, name);
		
	BreakDown (name, first, mi, last);

	cout << "First Name Entered :  " << first << endl;
	cout << "Last Name Entered :  " << last << endl;
	cout << "Middle Initial Entered :  " << mi << endl;

	cout << "Date? <MM/DD/YYYY>";
	getline (cin, date);

	getdate (date, month, day, year);
	cout << "Month Entered : " << month << endl;
	cout << "Day Entered : " << day << endl;
	cout << "Year Entered : " << year << endl;

	return 0;
}

void BreakDown (string name, string& first, string& mi, string& last)
{
	// pre  : name is initialized with a full name
	// post : first, mi, and last contain the individual components
        //        of that name
	first = name.substr(name.find(",") + 2, name.length() - name.find(",")-5);
	last = name.substr(0,name.find(","));
	mi = name.substr(name.find(".") - 1, 1);
}

void getdate (string date, string& month, string& day, string& year)
{

	month = date.substr (0,2);
	day = date.substr (3, 2);
	year = date.substr (6,9);

}
