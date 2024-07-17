#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or
 *		-1 if not found or array is NULL.
 *
 * Description: Prints the subarray being searched after each change.
 *              Always returns the first index where the value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t start = 0, end = size - 1, mid, i;

	if (array == NULL || size == 0)
		return (-1);

	while (start <= end)
	{
		printf("Searching in array: ");
		for (i = start; i <= end; i++)
			printf("%d%s", array[i], i == end ? "\n" : ", ");

		mid = start + (end - start) / 2;

		if (array[mid] == value)
		{
			if (mid == start || array[mid - 1] < value)
				return ((int)mid);
			end = mid;
		}
		else if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return (-1);
}
