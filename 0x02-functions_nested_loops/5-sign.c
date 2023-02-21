#include "main.h"
/**
 * print_sign - Prints the sign of a number.
 * @n: The number of which the sign will be printed.
 * Return: if n is greaterthan 0 return 1 and If n is lessthan 0 return -1,
 * if it its equal 0 return 0.
*/

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
