#include "function_pointers.h"

/**
 * print_name - Calls a function to print a name
 * @name: A pointer to a string representing the name to be printed
 * @f: pointer to a function that takes in a char pointer argument
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
