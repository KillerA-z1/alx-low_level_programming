#include "main.h"

/**
 * binary_to_uint - Function that converts a binary number to an unsigned int.
 * @b: the string to convert binary
 *
 * Return: the converted number, or NULL if not 0 or 1.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
		return (0);

		num <<= 1;
		if (*b == '1')
			num |= 1;
		b++;
	}
	return (num);
}
