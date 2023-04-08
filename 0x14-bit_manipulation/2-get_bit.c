#include "main.h"

/**
 * get_bit - Function that returns the value of a bit at a given index.
 * @n: Decimal number.
 * @index: The index,starting from 0 of the bit you want to get.
 *
 * Return: -1 if an error occured else value of bit at index.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int i;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	i = ((n >> index) & 1);
		return (i);
}
