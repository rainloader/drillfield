#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

void MakeRandomizedArray(int* array, int size);
bool IsRandomizedArray(int* array, int size);
void ShiftArray(int* array, int pos, int size);

int main()
{
	int array[ARRAY_SIZE] = {};
	for(int i=0; i<ARRAY_SIZE; i++)
		array[i] = i+1;

	printf("%s\n", IsRandomizedArray(array, ARRAY_SIZE)?"true":"false");
	MakeRandomizedArray(array, ARRAY_SIZE);
	printf("%s\n", IsRandomizedArray(array, ARRAY_SIZE)?"true":"false");
	for(int i=0; i<100; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}

void MakeRandomizedArray(int* array, int size)
{
	int* originArray = new int[size];

	for(int i=0; i<size; i++)
		originArray[i] = i+1;

	srand(time(NULL));
	
	for(int i=0; i<size; i++)
	{
		int originArraySize = size-i;
		int pos;
		do
		{
			pos = rand()%originArraySize;
		}while(originArray[pos] == i+1);
		array[i] = originArray[pos];
		ShiftArray(originArray, pos, originArraySize);
	}
	delete[] originArray;
}

bool IsRandomizedArray(int* array, int size)
{
	for(int i=1; i<=size; i++)
	{
		bool flag = false;
		if(i == array[i-1])
		{
			printf("Not randomized number \"%d\" exists.\n", i);
			return false;
		}
		for(int j=0; j<size; j++)
		{
			if(array[j] == i)
			{
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			printf("There is no number \"%d\"\n", i);
			return false;
		}
	}
	return true;
}

void ShiftArray(int* array, int pos, int size)
{
	for(int i=pos; i<size-1; i++)
	{
		array[i] = array[i+1];
	}
	array[size-1] = 0;
}



