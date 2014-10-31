#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ShiftArray(char* string, int source, int length, int shiftAmount);

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
	replaceString = new char[replaceStringLength+1];

	strncpy(sourceString, argv[2], sourceStringLength);
	strncpy(replaceString, argv[3], replaceStringLength);
	replaceString[replaceStringLength] = 0;

	char* stringBuffer = new char[sourceStringLength]; // string과 input과 일치할때 넣어준다.

	char c;
	int i = 0;
	while(c != EOF)
	{
		c = fgetc(pTargetFile);
		stringBuffer[i] = c;
		// source 문자열과 일치할 경우 stringBuffer에 넣어준다.
		if(sourceString[i] == c)
		{
			stringBuffer[i] = c;
			i++;
			if(i == sourceStringLength)
			{
				printf("%s", replaceString);
				i = 0;
			}
		}
		// stringBuffer에 문자열이 남아있을 경우 : stringBuffer의 문자열이 sourceString과 일치하는지 체크한다.
		else if(i != 0)
		{
			int k = 0;
			for(int j=0; j<=i; j++)
			{
				if(stringBuffer[j] == sourceString[k])
					k++;
				else
					k = 0;
			}
			for(int j=0; j<=i-k; j++)
			{
				printf("%c", stringBuffer[j]);
			}
			if(k != 0)
			{
				ShiftArray(stringBuffer, i-k, k, i-k);
			}
			i = k;
		}
		else
		{
			printf("%c", c);
		}
	}

	return 0;
}

void ShiftArray(char* string, int source, int length, int shiftAmount)
{
	if(shiftAmount > 0)
	{
		for(int i=source+length -1; i<=source; i--)
		{
			string[i+shiftAmount] = string[i];
		}
	}
	else
	{
		for(int i=source; i<source+length; i++)
		{
			string[i+shiftAmount] = string[i];
		}
	}
}


