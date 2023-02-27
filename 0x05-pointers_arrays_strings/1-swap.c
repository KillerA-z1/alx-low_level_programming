#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: pointer to a value
 * @b: pointer to b value
 */
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
