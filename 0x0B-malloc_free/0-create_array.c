#include "main.h"
#include <stdlib.h>

/**
 * create_array -Creates array of chars & initializes it with a specific char.
 * @size: The size of the array to be initialized.
 * @c: The specific char to initialize the array with.
 *
 * Return: If size equals to  0 or the function fails return NULL.
 *         Otherwise - a pointer to the array.
 */
char *create_array(unsigned int size, char c)
{
	char *char_array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	char_array = malloc(sizeof(char) * size);

	if (char_array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		char_array[i] = c;

	return (char_array);
}

