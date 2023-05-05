#include "main.h"
/**
 * flip_bits - Function that returns the number of bits you would need to flip
 *		to get from one number to another.
 * @n: Pointer to Positive numbers.
 * @m:Pointer to Positive numbers.
 *
 * Return: -1 if an error occured else 1 if it worked.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int sum = 0;
	int i = 0;

	sum = n ^ m;

	while (sum)
	{
		if (sum & 1)
		i++;
	sum = sum >> 1;
	}
	return (i);
}
