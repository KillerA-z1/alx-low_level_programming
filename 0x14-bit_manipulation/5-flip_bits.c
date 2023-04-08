#include "main.h"
/**
 * flip_bits - Counts the number of bits needed to be
 *             flipped to get from one number to another.
 * @n: Decimal number.
 * @m: Second decimal number.
 *
 * Return: bit differences between two numbers
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int result;
	int i = 0;

	result = n ^ m;

	while (result)
	{
		i = i + (result & 1);
		result >>= 1;
	}

	return (i);
}

