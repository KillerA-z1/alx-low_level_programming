#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: n is an integer value that will be valued
 * Description: prints the last digit of a number
 * Return: n value if lessthan 0 else return last_num
 */

int print_last_digit(int n)
{
	int last_num = n % 10;

	if (n < 0)
	{
		last_num = last_num * -1;
	}
	_putchar(last_num + '0');
	return (last_num);
}
