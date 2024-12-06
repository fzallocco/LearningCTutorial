#include <stdio.h>
/*resources on Pointers: https://www.cs.yale.edu/homes/aspnes/pinewiki/C%282f%29Pointers.html*/
/*#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)*/ //we can use macros to find array size
void rankAlgorithmBruteForce(int inputArray[], size_t arr_size, int rankArray[], int outputArray[])
{
	int i;
	int j;
	int m;
	for(i = 0; i < arr_size; i++)
	{
		int lowestMin = inputArray[i];
		int currentSum = 0;
		for(j = 0; j < arr_size; j++)
		{
			if(i != j)
			{
				int currentMin = inputArray[j];
				if(lowestMin > currentMin)
				{
					currentSum += 1;
				}
				rankArray[i] = currentSum;
			}
		}
	}
	
	for(m = 0; m < arr_size; m++)
	{
		outputArray[rankArray[m]] = inputArray[m];
	}
	/*printf("array's length: %d\n", arr_size);*/
}
int main(void)
{

	int i, j, m;
	int unsortedList[5] = {13, 9, 23, 10, 1};
	size_t nSize = sizeof(unsortedList) / sizeof(unsortedList[0]);
	/*size_t n = (&arr)[1] - arr;*/ //alternatively, we can use pointer arithmatic to find array size
	int rankList[nSize];
	int sortedList[nSize];
	rankAlgorithmBruteForce(unsortedList, nSize, rankList, sortedList);
	printf("this is the unsorted array: \n");
	for(i = 0; i < nSize; i++) printf("i:%d\tvalue:%d\n", i, unsortedList[i]);
	printf("\n");
	printf("this is the ranked array: \n");
	for(j = 0; j <nSize; j++) printf("j:%d\tvalue:%d\n", j, rankList[j]);
	printf("\n");
	printf("this is the sorted array: \n");
	for(m = 0; m <nSize; m++) printf("m:%d\tvalue:%d\n", m, sortedList[m]);
	return 0;
	
}