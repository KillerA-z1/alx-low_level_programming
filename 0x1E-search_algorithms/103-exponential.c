#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search_subarray - Searches for a value in a sorted subarray.
 * @array: A pointer to the first element of the array to search.
 * @start: The starting index of the subarray to search.
 * @end: The ending index of the subarray to search.
 * @target: The value to search for.
 *
 * Return: If the target is not present or the array is NULL, -1.
 *         Otherwise, the index where the target is located.
 *
 * Description: Prints the subarray being searched after each change.
 */
int binary_search_subarray(int *array, size_t start, size_t end, int target)
{
	size_t mid;
	size_t index;

	if (array == NULL)
		return (-1);

	while (start <= end)
	{
		printf("Searching in array: ");
		for (index = start; index <= end; index++)
			printf("%d%s", array[index], index == end ? "\n" : ", ");

		mid = start + (end - start) / 2;

		if (array[mid] == target)
			return (mid);
		if (array[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm
 * @array: A pointer to the first element of the sorted array of integers
 * @size: The number of elements in the array
 * @value: The value to search for within the array
 *
 * Return: The index where value is located
 *         If value is not present in array or if array is NULL, returns -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t left, right;
	int result;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
	{
		printf("Value checked array[0] = [%d]\n", array[0]);
		return (0);
	}

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	left = bound / 2;
	right = (bound < size) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	result = binary_search_subarray(array, left, right, value);

	return (result);
}
