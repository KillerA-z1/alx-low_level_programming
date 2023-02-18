#include <stdio.h>

/**
 * main - Prints 3 combination of numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int c = '0';
	int i, k;

	while (c <= '9')
	{
	i = c + 1;
	while (i <= '9')
	{
	k = i + 1;
	while (k <= '9')
	{
	putchar(c);
	putchar(i);
	putchar(k);

	if (c != '7' || i != '8' || k != '9')
	{
	putchar(',');
	putchar(' ');
	}
	k++;
	}
	i++;
	}
	c++;
	}

	putchar('\n');
	return (0);
}
