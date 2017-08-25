#include <iostream>
#include <fstream>
#include <string>
#include "linelist.h"

using namespace std;

void functionswitch(int intselection, LineList& l, string& selection, ofstream& outfile, string& filename);
int stringtoint(LineList l, string& selection);
void makelist(ifstream& infile, LineList& l);
void insert(LineList& l);
void writeout(ofstream& outfile, LineList& l, string& filename);

int main(int argc, char *argv[])
{
	LineList l;
	string selection;
	string filename = argv[1];
	ifstream infile;
	infile.open(filename.c_str());
	ofstream outfile;
	//outfile.open(filename, ios_base::app);	
	makelist(infile, l);
	if(l.getLength() > 0)
		l.printList();
	functionswitch(stringtoint(l, selection), l, selection, outfile, filename);
	if(l.getLength() > 0 && selection == "E")
		writeout(outfile, l, filename);
	return 0;
}

void functionswitch(int intselection, LineList& l, string& selection, ofstream& outfile, string& filename)
{
	while(intselection != 6){
		switch(intselection)
		{
		case 1:
			insert(l);
			break;
		case 2:
			l.deleteLine();
			break;
		case 3:
			if(l.getLength() > 0)
				l.printList();
			break;
		case 4:
			if(l.getLength() > 0)
				l.movePrevLine();
			break;
		case 5:
			if(l.getLength() > 0)
				l.moveNextLine();
			break;
		case 6:
			if(l.getLength() > 0)
				writeout(outfile, l, filename);
			break;
		default:
			break;
		}
		intselection = stringtoint(l, selection);
	}
}

int stringtoint(LineList l, string& selection)
{
	if(l.getCurrLineNum() > 0)
		cout << l.getCurrLineNum() << "> ";
	else
		cout << "0> ";
	getline(cin, selection);
	if(selection == "I")
		return 1;
	else if(selection == "D")
		return 2;
	else if(selection == "L")
		return 3;
	else if(selection == "P")
		return 4;
	else if(selection == "N")
		return 5;
	else if(selection == "E")
		return 6;
	else 
		return 0;
}

void makelist(ifstream& infile, LineList& l)
{
	string s;
	while(getline(infile,s)){
		l.insertLine(s);
	}
}

void insert(LineList& l){
	string newLine;
	if(l.getCurrLineNum() > 0)
		cout << l.getCurrLineNum() << "> ";
	else 
		cout << "0> ";
	getline(cin, newLine);
        l.insertLine(newLine);	
}

	
void writeout(ofstream& outfile, LineList& l, string& filename)
{
	outfile.open(filename.c_str());
	l.goToTop();
	if(l.getLength() <= 0)
		outfile << l.getCurrLine() << '\n';
	for(int i = 0; i < l.getLength(); i++){
		outfile << l.getCurrLine() << '\n';
		l.moveNextLine();
	}
}
