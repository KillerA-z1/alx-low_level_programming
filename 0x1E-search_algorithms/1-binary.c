#include "search_algos.h"
/**
 * binary_search - Searches for a value in a sorted array of integers.
 *
 * Description:
 * This function implements the binary search algorithm to find a specific
 * value within a sorted array of integers. It divides the search interval
 * in half repeatedly until the value is found or the interval is empty.
 *
 * The function prints the current array (or subarray) being searched
 * before proceeding with each step of the algorithm, providing a clear
 * visualization of the search process.
 *
 * @array: A pointer to the first element of the sorted array of integers.
 * @size: The number of elements in the array.
 * @value: The value to search for within the array.
 *
 * Return: The index where value is located.
 *         If value is not present in array or if array is NULL, returns -1.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, left, right;

	if (array == NULL)
		return (-1);

	left = 0;
	right = size - 1;
	while (right >= left)
	{
		printf("Searching in array: ");
		i = left;
		while (i < right)
		{
			printf("%d, ", array[i]);
			i++;
		}
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}
