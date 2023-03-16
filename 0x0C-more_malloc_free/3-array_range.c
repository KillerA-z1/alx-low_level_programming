#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates array of integers with values ranging from min to max
 *
 * @min: minimum integer value
 * @max: maximum integer value
 *
 * Return: pointer to the newly created array, or NULL if it fails
 */
int *array_range(int min, int max)
{
	int *arr, idx, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	arr = malloc(sizeof(int) * size);

	if (arr == NULL)
		return (NULL);

	for (idx = 0; idx < size; idx++)
		arr[idx] = min++;

	return (arr);
}

