// Preston Shankle
// CSC245 -- Dr. Digh
// 1-25-2017

#include <iostream>
#include <string> 
using namespace std;

const int SIZE = 100;

struct DateType
{
	string month;
	int day;
	int year;
};

struct EventType
{
	string place;
	date DateType;
};

void PrintStruct (DateType Holiday);
void AssignMonth (EventType Dates[]);

int main()
{
	DateType Holiday = {"February", 14, 2017};
	EventType Date[SIZE];	

	PrintStruct (Holiday);
	AssignMonth (Dates);
	return 0;
}

void PrintStruct (DateType Holiday)
{
	// pre  : Holiday is intialized with three field values
	// post : Function prints date of Holiday in form mm dd, yy
 	cout << Holiday.month << " " << Holiday.day << ", " << Holiday.year << endl;



}

void AssignMonth (EventType Dates[])
{
	// pre  : none 
	// post : The month field of every date record in array is assigned a month 
	for(int i = 0; i < sizeof(Dates);i++)
	{
		Dates[i].month = "February";	
	}

}
