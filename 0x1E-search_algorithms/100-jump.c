#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches values in a sorted array using jump search algorithm
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, -1 otherwise
 */
int jump_search(int *array, size_t size, int value)
{
	int step, step_size, step_index, prev_index;

	if (array == NULL || size == 0)
		return (-1);

	step_size = (int)sqrt((double)size);
	step = 0;
	prev_index = step_index = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", step_index, array[step_index]);

		if (array[step_index] == value)
			return (step_index);
		step++;
		prev_index = step_index;
		step_index = step * step_size;
	} while (step_index < (int)size && array[step_index] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev_index, step_index);

	for (; prev_index <= step_index && prev_index < (int)size; prev_index++)
	{
		printf("Value checked array[%d] = [%d]\n", prev_index, array[prev_index]);
		if (array[prev_index] == value)
			return (prev_index);
	}

	return (-1);
}
