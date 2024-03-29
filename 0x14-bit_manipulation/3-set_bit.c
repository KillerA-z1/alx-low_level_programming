#include "main.h"
/**
 * set_bit - Function that sets the value of a bit to 1 at a given index.
 * @n: pointer to Positive numbers.
 * @index: The index,starting from 0 of the bit you want to get.
 * Return: -1 if an error occured else 1 if it worked.
 *
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8))
		return (-1);
	*n = *n | (1 << index);
		return (1);
}
