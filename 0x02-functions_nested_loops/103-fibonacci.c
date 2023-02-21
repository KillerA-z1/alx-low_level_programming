#include <stdio.h>

/**
 *main - Entery point
 *Description: Computes and prints sum of even Fibonacci numbers < 4,000,000
 *Return: Always 0.
 */

int main(void)
{
	int num1 = 0, num2 = 1, next = 0;
	int sum = 0;

	for (; next < 4000000;)
	{
	next = num1 + num2;
	num1 = num2;
	num2 = next;

	if (next % 2 == 0)
	sum += next;
	}

	printf("%i\n", sum);

return (0);
}

