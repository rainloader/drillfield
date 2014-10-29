#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc != 4)
	{
		printf("[USAGE] : inputfile sourceString replaceString\n");
		exit(1);
	}
	
	FILE* pTargetFile;
	char* sourceString;
	char* replaceString;
	pTargetFile = fopen(argv[1], "r");

	if(pTargetFile == NULL)
	{
		printf("[ERROR] : Wrong input file\n");
		exit(1);
	}
	
	int sourceStringLength = strlen(argv[2]);
	int replaceStringLength = strlen(argv[3]);

	sourceString = new char[sourceStringLength];
	replaceString = new char[replaceStringLength];

	



	return 0;
}
