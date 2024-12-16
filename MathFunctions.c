/*Matrix Multiplication Tutorial:https://www.youtube.com/watch?v=GetaI7KhbzM*/
/*Matrix Multiplication Reference:https://ghenshaw-work.medium.com/3-ways-to-understand-matrix-multiplication-fe8a007d7b26*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void floatMatrixMultiplication(float *matrixA, float *matrixB, float *matrixC, int rowsA, int columnsA, int columnsB) {
    int i, j, k;

    // Initialize matrixC to zero
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < columnsB; j++) {
            *(matrixC + i * columnsB + j) = 0.0f;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < rowsA; i++) {           // Rows of matrixA
        for (j = 0; j < columnsB; j++) {    // Columns of matrixB
            for (k = 0; k < columnsA; k++) { // Columns of matrixA / Rows of matrixB
                *(matrixC + i * columnsB + j) += 
                    (*(matrixA + i * columnsA + k)) * (*(matrixB + k * columnsB + j));
            }
        }
    }

    // Print the resulting matrixC
    printf("Resultant Float Matrix C:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < columnsB; j++) {
            printf("%.2f ", *(matrixC + i * columnsB + j));
        }
        printf("\n");
    }
}

void integerMatrixMultiplication(int *matrixA, int *matrixB, int *matrixC, int rowsA, int columnsA, int columnsB)
{
    int i, j, k;

    // Initialize matrixC to zero
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < columnsB; j++) {
            *(matrixC + i * columnsB + j) = 0;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < rowsA; i++) {           // Rows of matrixA
        for (j = 0; j < columnsB; j++) {    // Columns of matrixB
            for (k = 0; k < columnsA; k++) { // Columns of matrixA / Rows of matrixB
                *(matrixC + i * columnsB + j) += 
                    (*(matrixA + i * columnsA + k)) * (*(matrixB + k * columnsB + j));
            }
        }
    }

    // Print the resulting matrixC
    printf("Resultant Integer Matrix C:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < columnsB; j++) {
            printf("%d ", *(matrixC + i * columnsB + j));
        }
        printf("\n");
    }
}
int differenceOfTwoNumbers(int *x, int *y)
{
	int difference = *x - *y;
	return difference;
}
int sumOfTwoNumbers(int *x, int *y)
{
	int sum = *x + *y;
	return sum;
}
int productOfTwoNumbers(int *x, int *y)
{
	/*int i;
	int product;
	for(i = 0; i < n; i++)
	{
		product += y;
	}*/
	int product;
	product = *x * *y;
	return product;
}
int quotientOfTwoNumbers(int *x, int *y)
{
	int quotient;
	quotient = *x / *y;
	return quotient;
}
int main(void)
{
	int m = 4;
	int n = 2;
	int *num1 = &m;
	int *num2 = &n;
	int sum = sumOfTwoNumbers(num1, num2);
	int difference = differenceOfTwoNumbers(num1, num2);
	int product = productOfTwoNumbers(num1, num2);
	int quotient = quotientOfTwoNumbers(num1, num2);
	printf("sum is: %d\n", sum);
	printf("difference is: %d\n", difference);
	printf("product is: %d\n", product);
	printf("quotient is: %d\n", quotient);
	printf("\n");
	printf("Now testing Vector Products:\n");
	printf("\n");
	int matrixA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int matrixB[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	int matrixC[3][2] = {0};
	int rowsA = 3;
	int columnsA = 3;
	int columnsB = 2;
	// Example matrices (float)
    float A[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };

    float B[3][2] = {
        {1.0f, 2.0f},
        {3.0f, 4.0f},
        {5.0f, 6.0f}
    };

    float C[3][2] = {0.0f}; // Resultant matrix
	
	integerMatrixMultiplication(&matrixA[0][0], &matrixB[0][0], &matrixC[0][0], rowsA, columnsA, columnsB);
	printf("\n");
	floatMatrixMultiplication(&A[0][0], &B[0][0], &C[0][0], rowsA, columnsA, columnsB);
	return 0;
}