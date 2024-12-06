#include <stdio.h>
/*resources on Pointers: https://www.cs.yale.edu/homes/aspnes/pinewiki/C%282f%29Pointers.html*/
/*#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)*/ //we can use macros to find array size
void print(int *a)
{
	printf("array's value by pointer a is now: %d\n", a[0]);
}
void printArrayForLoop(int *z, size_t size)
{
	/*int m = *z; //m is dereferencing z; This solutions is inefficient
	printf("array's value through z is now: %d\n", m);
	m++;
	printf("array's value through z is now: %d\n", m);
	m++;
	printf("array's value through z is now: %d\n", m);*/
	int j;
	for(j = 0; j<size; j++)
	{
		printf("z's value at %d\t is : %d\n", j, *z);
		z++;
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
void printArray(int a[], size_t size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("array's value at %d\t is %d\n", i, a[i]);
	}
}
int main(void)
{
	int b[3] = {1, 2, 3};
	int * r = b;
	int * n = b;
	int * s = b;
	print(r); //prints array's value at index 0, which is 1
	print(r + 1); //prints array's value at index 1, which is 2
	print(r + 2); //prints array's value at index 2, which is 3
	printf("dereferencing r's first value: %d\n", *r); //this will print out 0
	r++; //you can increment the integer pointer r by 1, and plug it into the next print function
	printf("dereferencing r's second value: %d\n", *r); //this will print out 2
	printf("dereferencing r's third value: %d\n", *(r + 1)); //r incremented by 1, is subsequently incremented by 1 again
	printf("\n");
	printf("Test of the recursive function that loops over the array\n");
	size_t size = (&b)[1] - b; //size variable is set to address of b array
	printf("array's size is: %d\n", size);
	printArrayForLoop(s, size);
	recursivePrint(n, size);
	printArray(b, size);
	return 0;
}