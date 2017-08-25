#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

struct RecType
{
	int age;
	float weight;
	char gender;
};

int main()
{	
	int num = 5;
	int lowcasecount = 0;
	int *intPtr = NULL;
	//intPtr = &num;
	*intPtr = *intPtr * 10;
	printf("intPtr points to:\t\t\t\t%u\n", *intPtr);
	RecType *recPtr = new RecType;
	recPtr -> age = 25;
	recPtr -> weight = 190;
	recPtr -> gender = 'M';
	recPtr -> age += 5;	
   	printf("Three fields pointed to by recPtr:\t\t%u %g %c\n", recPtr -> age,
		recPtr -> weight, recPtr -> gender);
	delete recPtr;
	recPtr = NULL;
	char *strPtr = new char[50];
	strcpy (strPtr, "Operating Systems");
	printf("strPtr points to:\t\t\t\t%s\n",strPtr);
	for(int i = 0; i < strlen(strPtr); i++){
	if(islower(*(strPtr+i)))
		lowcasecount++;
	}
	printf("LowerCase Letters Pointed To By strPtr :\t%u\n", lowcasecount);
	strPtr = strPtr + 10;
	printf("Printing strPtr after adding 10 :\t\t%s\n", strPtr);
	strPtr = strPtr - 10;
	delete strPtr;
	return 0;
}
