#include "main.h"
/**
 * clear_bit - Function that sets the value of a bit to 0 at a given index.
 * @n: Pointer to Positive numbers.
 * @index: The index,starting from 0 of the bit you want to get.
 *
 * Return: -1 if an error occured else 1 if it worked.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8))
		return (-1);
	*n = *n & (~(1 << index));
		return (1);
}

