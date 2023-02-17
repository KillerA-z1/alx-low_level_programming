#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Description: Print base 16 numbers
 * Return: Always 0 (success)
 */
int main(void)
{
	char chl = 'a';
	char num = '0';

	while (num <= '9')
	{
		putchar(num);
		num++;
	}
	while (chl <= 'f')
	{
		putchar(chl);
		chl++;
	}
	putchar('\n');
	return (0);
}
