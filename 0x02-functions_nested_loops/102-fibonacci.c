#include <stdio.h>

/**
 * main - Prints first 50 Fibonacci numbers
 *
 * Return: 0
 */

	int main(void)
	{
	int i = 0;
	long num1 = 0, num2 = 1, sum;

	while (i < 50)
	{
	sum = num1 + num2;
	printf("%lu", sum);

	num1 = num2;
	num2 = sum;

	if (i == 49)
	printf("\n");
	else
	printf(", ");

	i++;
	}

	return (0);
}

