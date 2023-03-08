#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 *
 * @s: pointer to the string to measure
 *
 * Return: the length of the string
 */
int _strlen_recursion(char *s)
{
	int lengeth = 0;

	if (*s)
	{
		lengeth++;
		lengeth += _strlen_recursion(s + 1);
	}

	return (lengeth);
}

