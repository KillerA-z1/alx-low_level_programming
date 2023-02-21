#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - natural numbers
 * @n: input number.
 * Description: prints all natural number from n tO 98
 * Return: void
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
	for (i = n; i <= 98; i++)
	{
	if (i == 98)
	{
	_putchar(i / 10 + '0');
	_putchar(i % 10 + '0');
	_putchar('\n');
	}
	else
	{
	_putchar(i / 10 + '0');
	_putchar(i % 10 + '0');
	_putchar(',');
	_putchar(' ');
	}
	}
	}
	else
	{
	for (i = n; i >= 98; i--)
	{
	if (i == 98)
	{
	_putchar(i / 10 + '0');
	_putchar(i % 10 + '0');
	_putchar('\n');
	}
	else
	{
	_putchar(i / 10 + '0');
	_putchar(i % 10 + '0');
	_putchar(',');
	_putchar(' ');
	}
	}
	}
}

