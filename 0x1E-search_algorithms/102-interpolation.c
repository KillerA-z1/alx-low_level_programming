#include "search_algos.h"
/**
 * interpolation_search - Searches for a value in a sorted array using
 *                        interpolation search algorithm.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is found, or -1 if the value is not
 *         present in the array.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t position, lower_bound, upper_bound;
	double fraction;

	if (array == NULL)
		return (-1);

	lower_bound = 0;
	upper_bound = size - 1;

	while (size)
	{
		fraction = (double)(upper_bound - lower_bound) /
				   (array[upper_bound] - array[lower_bound]) *
				   (value - array[lower_bound]);
		position = (size_t)(lower_bound + fraction);
		printf("Value checked array[%d]", (int)position);

		if (position >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[position]);
		}

		if (array[position] == value)
			return ((int)position);

		if (array[position] < value)
			lower_bound = position + 1;
		else
			upper_bound = position - 1;

		if (lower_bound == upper_bound)
			break;
	}

	return (-1);
}
