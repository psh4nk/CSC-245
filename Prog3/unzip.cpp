#include <string> 
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct huffman{
	int ascii;
	string code;
};

void stringbuilder(char *argv[]);
void writeout(string result, string filename);

int main(int argc, char *argv[])
{
	stringbuilder(argv);	
	return 0;	
}

void stringbuilder(char *argv[])
{
	// Pre	:	 filename has been inputted into argv by user
	// Post	:	 String has been rebuilt from the Huffman data contained in .zip file
	vector<huffman> array;
	string s, a;
	int i = 0;
	int length;
	string filename;
	if(argv[1])
		filename = argv[1];
	else
	{
		cerr << "UNZIP: Filename not entered. Exiting.\n";
		exit(0);
	}
	if(filename.find(".zip") == std::string::npos)
	{
		cerr << "UNZIP: Invalid file format. Must be of file type .zip\n";
		exit(0);
	}
	ifstream infile;
	infile.open(filename.c_str());
	getline(infile, s);
	stringstream convert(s);
	convert >> length;
	char *String[length];
	while(getline(infile,a))
	{
		int asciival = 0;
		int currcode = 0;
		int pos = a.find(' ');
		string temp = a.substr(0, a.find(' '));	
		stringstream convert(temp);
		array.push_back(huffman());
		convert >> asciival;
		array[i].ascii = asciival;
		string temp2 = a.substr(a.find(' ') + 1, 100);
		array[i].code = temp2;	
		i++;			
	}
	int pos = 0, currlen = 1;
	string result;
	for(int j = 0; j < array.size() - 1; j++)
	{	
		currlen = 0;
		for(int k = 0; k < array.size() - 1; k++)
       		{
			currlen = 1;
			for(int i = 0; i < array.size() - 1; i++)
			{
				if(array[k].code == a.substr(pos, currlen))
				{
					result += (char)array[k].ascii;	
					pos += currlen;
					currlen = 1;
				}
				else
				{
					currlen++;
				}
			}
		}
	}
	writeout(result, filename);		
}

void writeout(string result, string filename){
	// Pre	:	String result has been filled, filename has been filled
	// Post	:	Result is written out to file
	ofstream outfile;
	filename = filename.substr(0, filename.find(".zip"));
	outfile.open(filename.c_str());
		outfile << result;
	cout << "File Successfully Inflated Back to Original\n";
}
