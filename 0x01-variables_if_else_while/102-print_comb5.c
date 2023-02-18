#include <stdio.h>
#include <unistd.h>
/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of 2-digit numbers.
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int c = 48, k, i, j;

	while (c <= 57)
	{
	i = 48;
	while (i <= 57)
	{
	k = 48;
	while (k <= 57)
	{
	j = 48;
	while (j <= 57)
	{
	if (((k + j) > (c + i) && k >= c) || c < k)
	{
	putchar(c);
	putchar(i);
	putchar(' ');
	putchar(k);
	putchar(j);
	if (c + i + k + j == 227 && c == 57)
	{
	break;
	}
	else
	{
	putchar(',');
	putchar(' ');
	}
	}
	j++;
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
