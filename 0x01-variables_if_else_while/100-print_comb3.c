#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Description: prints all possible different combinations of two digits
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int c = '0';
	int i;

	while (c <= '9')
	{
	i = c + 1;
	while (i <= '9')
	{
	putchar(c);
	putchar(i);
	if (c != '8' || (c == '8' && i != '9'))
	{
	putchar(',');
	putchar(' ');
	}
	i++;
	}
	c++;
	}

	putchar('\n');
	return (0);
}
