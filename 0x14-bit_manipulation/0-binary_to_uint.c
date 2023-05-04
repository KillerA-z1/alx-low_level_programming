#include "main.h"

/**
 * binary_to_uint - Function that converts a binary number to an unsigned int.
 * @b: is pointing to a string of 0 and 1 chars
 *
 * Return: the converted number,but if  b is NULL or not 0 or 1 return 0.
 */

unsigned int binary_to_uint(const char *b)
{

	unsigned int i = 0;
	unsigned int num = 0;

	for (; b[i] != '\0'; i++)
	{
	if (b[i] != '0' && b[i] != '1')
		return (0);
	num <<= 1;
	if (b[i] == '1')
	num |= 1;
	}
	return (num);
	}
