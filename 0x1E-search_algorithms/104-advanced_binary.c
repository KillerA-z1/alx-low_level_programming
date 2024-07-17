#include "search_algos.h"
/**
 * advanced_binary_recursive - Recursively searches a value in a sorted array.
 * @array: A pointer to the first element of the array to search.
 * @start: The starting index of the subarray to search.
 * @end: The ending index of the subarray to search.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int value)
{
	size_t i, mid;

	if (start > end)
		return (-1);

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
		printf("%d%s", array[i], i == end ? "\n" : ", ");

	mid = (start + end) / 2;

	if (array[mid] == value)
	{
		if (mid == start || array[mid - 1] < value)
			return ((int)mid);
		return (advanced_binary_recursive(array, start, mid, value));
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, end, value));
	else
		return (advanced_binary_recursive(array, start, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or
 *		-1 if not found or array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
