#include "main.h"
#include <stdlib.h>


/**
 * _calloc - function that allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size in bytes of each element
 *
 * Return: void pointer to the allocated memory, NULL if failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	char *filler;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	filler = ptr;

	for (i = 0; i < (nmemb * size); i++)
		filler[i] = '\0';

	return (ptr);
}

