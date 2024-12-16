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
void recursivePrint(int *z, size_t size)
{
	if(size <= 0) {
		return;
	}

	printf("Value at address %p is: %d\n",(void *)z,*z);
	recursivePrint(z+1, size-1);
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
	int myList[] = {12, 24, 45, 2, 89, 3, 100};
	int* a = myList;
	/*size_t size = (&myList)[1] - myList;*/
	size_t size = sizeof(myList) / sizeof(myList[0]);
	printArrayMemoryAddresses(a, size);
	printf("Matrix Test\n");
	int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};
    int* ptr1 = arr1;
    int* ptr2 = arr2;
    int* matrix[] = {ptr1, ptr2};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", *matrix[i]++);
        }
        printf("\n");
    }
	
	printf("Second Array Test\n");
	int arr[] = {12, 24, 36, 48, 60};

    // size_t
    size_t thisSize = sizeof(arr) / sizeof(arr[0]);
    printf("Size of arr: %zu\n", thisSize);  // Output: 5
    printf("size of size_t: %zu\n", sizeof(size_t));  // Output: 8 (bytes) -> 64 bits which is memory safe
    printf("int size in bytes: %zu\n", sizeof(int));  // Output: 4 (bytes) -> 32 bits
    // z -> size_t
    // u -> unsigned int
    // %zu -> size_t
    // src: https://cplusplus.com/reference/cstdio/printf/

	return 0;
}