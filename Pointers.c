#include <stdio.h>
/*resources on Pointers: https://www.cs.yale.edu/homes/aspnes/pinewiki/C%282f%29Pointers.html*/
/*https://www.youtube.com/watch?v=2ybLD6_2gKM&list=PLtr3JKh9YHSuaOqDn3vdqvDLlxmg29DWs&index=177*/
void print(int *a) /*this function not only accepts pointers to integers but also to arrays*/
{
	printf("a[1] = %d\n", a[1]);
}
int main(void)
{
	int a[3] = {1,2,3}; /*I'm declaring an array of three integers*/
	/*a is really a memory address & when we access it with array notation, we read values stored at that memory address*/
	int *b; /*this is a pointer to an integer*/
	b = a; /*assign an array to an integer: arrays can be treated like pointers and pointers can be treated like arrays*/
	/*a is decaying to a pointer, or the memory address that a is storing is going to be used and stored in b*/
	printf("b: %p\na: %p\n", b, a);
	printf("Here we call the print function that accepts pointers to integers/arrays\n");
	print(a);
	printf("Here we call the print function that accepts pointers to integers/arrays again, cutting the array by one integer:\n");
	print(a + 1);
	/*printf("Here we call the print function that accepts pointers to integers/arrays again, cutting the array by one integer:\n");
	print(a + 1);*/
	/*below the printf function executes the same instructions*/
	// 1, 2, 3
	printf("pointer b fetches array a's memory reference and seeks for the value one block over\n");
	/*pointer b fetches array a's memory reference and seeks for the value one block over*/
	printf("b[1] = %d\n", b[1]);
	/*narray a's memory referenced is fetched by the compiler and the value one block over is printed out*/
	printf("narray a's memory referenced is fetched by the compiler and the value one block over is printed out\n");
	printf("a[1] = %d\n", a[1]);
	printf("*b means dereferencing the pointer, in other words, go get whatever value is stored at b in the memory: which is array a's first value (1)\n");
	printf("*b = %d\n", *b);
	printf("*a = %d\n", *a);
	printf("This allows us to execute clever instructions such as referencing values in an array through pointer manipulation as shown below:\n");
	printf("*(b + 1) = %d\n", *(b + 1));
	printf("*(a + 2) = %d\n", *(a + 2));
	printf("*(b + 1) = %d\n", *(b + 2));
	b++;
	printf("by incrementing the array's pointer's b with b++, you can move over to the subsequent reference:\n");
	printf("*b = %d\n", *b);
	b++;
	printf("*b = %d\n", *b);
	/*b++;
	printf("*b = %d\n", *b);*/
	/*The below code is not going to work because we cannot assign arrays to arrays. 
	Even though pointers and arrays are both memory addresses, they work differently*/
	/*int c[3] = {2, 4, 5};
	a = c;
	a++;
	printf("\n\na[1] = %d\n", a[1]);*/
	return 0;
}