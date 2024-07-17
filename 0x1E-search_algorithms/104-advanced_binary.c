#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary_recursive - Recursively searches value in a sorted array of
 * integers using the Binary search algorithm
 *
 * @array: input array
 * @start: starting index of the current subarray
 * @end: ending index of the current subarray
 * @target: value to search for
 * Return: index of the target, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int target)
{
	size_t i, mid;

	if (start > end)
		return (-1);

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
		printf("%d%s", array[i], i == end ? "\n" : ", ");

	mid = start + (end - start) / 2;

	if (array[mid] == target)
	{
		if (mid == start || array[mid - 1] < target)
			return ((int)mid);
		return (advanced_binary_recursive(array, start, mid, target));
	}
	if (array[mid] < target)
		return (advanced_binary_recursive(array, mid + 1, end, target));
	return (advanced_binary_recursive(array, start, mid - 1, target));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search for
 * Return: index of the value, or -1 if not found or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
