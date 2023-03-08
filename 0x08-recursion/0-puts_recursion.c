#include "main.h"

/**
 * _puts_recursion - Prints a string followed by a new line
 * @s: Pointer to the string to be printed
 *
 * Return: Nothing
 */
void _puts_recursion(char *s)
{
	/* Check if we have reached the end of the string */
	if (*s)
	{
		/* Print the current character */
		_putchar(*s);
		/* Call the function recursively with the next character */
		_puts_recursion(s + 1);
	}
	else
	{
		/* We have reached the end of the string, print a new line */
		_putchar('\n');
	}
}

