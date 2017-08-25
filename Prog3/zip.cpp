#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "huffman.h"
using namespace std;

void CountLetters (int Letters[], string& s);
void insertLetters (const int Letters[], HuffmanTree& tree);
void openFile(HuffmanTree& tree, int& argc, char *argv[]);
string writeout(string filename, HuffmanTree& tree, string& s);

const int NumLetters = 256;

int main(int argc, char *argv[])
{
	HuffmanTree tree;
	openFile(tree, argc, argv);
	return 0;
}

void CountLetters (int Letters[], string& s)
{
	// Pre	: Letters has been initialized, string s contains file contents
	// Post	: Number of total characters has been determined

	char ch;

	for (char ch = char(0);  ch <= char(126);  ch++)
            Letters[ch] = 0;
 	bool ran = false;	
         for(int i = 0; i < s.length() + 1; i++)
         {
	  	if(!ran)
		{
			ch = s[i];
			ran = true;
		}
		else
		{
		 Letters[ch] += 1;
		 ch = s[i];
		}
	 }
	 ch = '\n';
	 Letters[ch] += 1;
}

void insertLetters (const int Letters[], HuffmanTree& tree)
{
 	// Pre	: Tree has been initialized, Letters[] contains letter counts
	// Post	: All characters are inserted into the tree along with their weights from Letters[]

  	for (char ch = char(0);  ch <= char(126);  ch++)
	{
	  if ( (Letters[ch] != 0) && (ch != '\n') && (ch != ' ') )      
		tree.insert(ch, Letters[ch]);	  
	  else if ( (Letters[ch] != 0) && (ch == '\n') )
	        tree.insert('\n',Letters[ch]); 
       	  else if ( (Letters[ch] != 0) && (ch == ' ') )
	  	tree.insert(' ', Letters[ch]);
	}
}

void openFile(HuffmanTree& tree, int& argc, char *argv[])
{
	// Pre	: Tree has been initialized but contains no data
	// Post	: Zip file is written out and program exits

	int Letters[NumLetters] = {};
	string filename, arg, s;	
	bool print = false;	
	if(argv[1])
		filename = argv[1];
	else
	{
		cerr << "ZIP: Invalid input\nTry 'ZIP --help' for more information.\n";
		exit(0);
	}
	ifstream infile;
	infile.open(filename.c_str());
	if(!infile.is_open())
	{
		if(filename == "--t")
			print = true;
		else if(filename == "--help"){
			string help;
			ifstream helpfile;
			helpfile.open("help");
			while(getline(helpfile, help))
				cout << help << endl;
			exit(0);
		}
		else
		{
			cerr << "ZIP: Invalid input\nCheck to see if file exists\nTry `ZIP --help' for more information.\n";
			exit(0);
		}
	}
	if(argv[2])
	{
		filename = argv[2];
		infile.open(filename.c_str());
		if(!infile.is_open()){
			cerr << "ZIP: File does not exist.\nTry 'ZIP --help' for more information.\n";
			exit(0);
		}
	}

	getline(infile, s);
	CountLetters(Letters, s);
	insertLetters(Letters, tree);
	tree.build();
	string result = writeout(filename, tree, s);
	if(print)
		tree.PrintTable();	
	cout << "\nFile Successfully Compressed To " << result.length()  << " Bits (" << (1 - (double)(((double)result.length())/((double)((double)tree.GetNumChars()*8))))*100 << "% Less)." << endl;
}

string writeout(string filename, HuffmanTree& tree, string& s)
{
	// Pre	: Tree has been built, filename has been filled
	// Post	: Result is written out to file
	
	ofstream outfile;
	filename = filename + ".zip";
	outfile.open(filename.c_str());
	outfile << tree.GetNumChars() << endl;
        for(int i = 0; i < tree.numNodes() ; i++)
        {
                if(tree.GetChar(i) != '\0')
                        outfile << (int)tree.GetChar(i) << " " << tree.GetCode(tree.GetChar(i)) << endl;
        }
	string result;
        for (int i = 0; i < s.length(); i++)
        {
                string code = tree.GetCode(s[i]);
                result += code;
        }
        outfile << result;
	return result;
}

