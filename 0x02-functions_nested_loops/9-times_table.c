#include "main.h"

/**
 *times_table - Entery point
 *Description: prints the 9 times table
 *Return: void
 */
void times_table(void)
{
	int num = 0, mult = 1, prod = 0;

	while (num <= 9)
	{
	_putchar('0');
	mult = 1;

	while (mult <= 9)
	{
	_putchar(',');
	_putchar(' ');
	prod = num * mult;
	if (prod <= 9)
	_putchar(' ');
	else
	_putchar((prod / 10) + '0');
	_putchar((prod % 10) + '0');
	mult++;
	}
	_putchar('\n');
	num++;
	}
	}

