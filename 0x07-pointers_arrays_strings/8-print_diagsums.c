#include "main.h"


/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix
 * @size: size of the matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int index, sum1 = 0, sum2 = 0;

	/* Compute sum of first diagonal */
	for (index = 0; index < size; index++)
		sum1 += a[index * (size + 1)];

	/* Compute sum of second diagonal */
	for (index = 1; index <= size; index++)
		sum2 += a[index * (size - 1)];

	printf("%d, %d\n", sum1, sum2);
}

