#include <stdio.h>
#include <stdlib.h>

void printArrayMemoryAddresses(int *arr, size_t size)
{
	int i;
	for(i = 0; i<size; i++)
	{
		printf("array value: %d at memory address: %p\t", *arr, arr);
		printf("Using & dereferencing pointer: %p\n", &arr);
		printf("\n");
		arr++;
	}
}
int main(void)
{
	printf("testing null pointers and array pointers\n");
	int intNum = 10;
	float fNumber = 3.14;
	void* vptr;
	vptr = &intNum;
	printf("this is integer number via void pointer: %d\n", *(int*)vptr);
	vptr = &fNumber;
	printf("this is float number via void pointer: %.2f\n", *(float*)vptr);
	int* xnm = NULL;
	printf("this is null pointer: %p\n", (void*)xnm);
	printf("1. initial xnm value: %p\n", (void*)xnm);
	//check for Null before using
	if (xnm == NULL) printf("2. xnm is NULL, cannot dereference\n");
	//allocate memory
	xnm = malloc(sizeof(int)); //allocate 4 bytes, or 32 bits
	/*int z = 2;
	xnm = &z;*/
	*xnm = 2;
	if(xnm == NULL)
	{
		printf("3. Memory allocation failed\n");
		return 1;
	}else{printf("3. %p is the memory reference of %d\n", xnm, *xnm);}
	
	// Clean up
    free(xnm);
    xnm = NULL;  // Set to NULL after freeing
	
	if(xnm == NULL)
	{
		printf("4. xnm is NULL, safely avoided use after free\t");
		printf("%p is the memory reference of %d\n", xnm, (void*)xnm);
		/*return 0;*/
	}else{printf("4. memory free-up failed\n");}
	
	printf("Array Test\n");
	int myList[7] = {12, 24, 45, 2, 89, 3, 100};
	int* a = myList;
	/*size_t size = (&myList)[1] - myList;*/
	size_t size = sizeof(myList) / sizeof(myList[0]);
	printArrayMemoryAddresses(a, size);
	
	return 0;
}