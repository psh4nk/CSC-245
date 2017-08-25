#include <iostream>
#include "linelist.h"

LineList::LineList()
{
	LineNode *line = new LineNode;
	LineNode *line2 = new LineNode;

	line -> info = topMessage;
	currLine = line;
	currLineNum = 0;
	length = 0;
	line2 -> info = bottomMessage;
	currLine -> back = NULL;
	currLine -> next = line2;
	line2 -> back = line;
	line2 -> next = NULL;
}

void LineList::goToTop() 
{
	// Post : Advances currLine to line 1
	while(currLine -> back -> info != topMessage)	
		movePrevLine();
	

	
}

void LineList::goToBottom() 
{
	// Post : Advances currLine to last line
	while(currLine -> next -> info != bottomMessage)
		moveNextLine();
	
}

void LineList::insertLine(string newLine)
{
	// post : newLine has been inserted after the current line
	LineNode *newNode = new LineNode;
	LineNode *backNode = new LineNode;

	backNode = currLine;

	newNode -> info = newLine;
	backNode -> next -> back = newNode;
	newNode -> next = backNode -> next;
	newNode -> back = backNode;
	backNode -> next = newNode;

	currLine = newNode;
	currLineNum++;
	length++;
}

void LineList::deleteLine()
{
	// post : deletes the current line leaving currentLine
	//	  pointing to line following
	LineNode *backNode = new LineNode;
	LineNode *nextNode = new LineNode;
	
	if(currLine -> info != bottomMessage)
	{	
		backNode = currLine -> back;
		nextNode = currLine -> next;
		backNode -> next = nextNode;
		nextNode -> back = backNode;
		currLine = nextNode;
		length--;
	}
}

void LineList::printList() 
{
	int lineNum = 1;
	LineNode *mark = currLine;
	goToTop();
	int markNum = currLineNum;
	LineNode *curr = currLine;
 	goToBottom();	
	while(curr -> info != bottomMessage)
	{
		std::cout << markNum << "> " << curr -> info << endl;
		curr = curr -> next;
		markNum++;
	}
}

string LineList::getCurrLine() const
{
	return currLine -> info;
}

void LineList::moveNextLine()
{
	// Post : Advances currLine (unless already at last line)
	if(currLine -> next -> info != bottomMessage)
	{
		currLine = currLine -> next;
		currLineNum++;
	}
}

void LineList::movePrevLine()
{	// Post : Advances currLine (unless already at last line)
	if(currLine -> back -> info != topMessage && currLine -> info != topMessage)
	{
		currLine = currLine -> back;
		currLineNum--;
	}
}

int LineList::getCurrLineNum() const
{
	return currLineNum;
}

int LineList::getLength() const
{
	return length;
}


