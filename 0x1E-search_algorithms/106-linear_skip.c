#include <stdio.h>
#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *express_lane;

	if (list == NULL)
		return (NULL);

	current = list;
	express_lane = list->express;
	while (express_lane != NULL)
	{
		printf("Value checked at index [%ld] = [%d]\n", express_lane->index,
		express_lane->n);
		if (express_lane->n >= value)
			break;
		current = express_lane;
		express_lane = express_lane->express;
	}

	if (express_lane == NULL)
	{
		express_lane = current;
		while (express_lane->next != NULL)
			express_lane = express_lane->next;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", current->index,
	express_lane->index);

	while (current != NULL && current->index <= express_lane->index)
	{
		printf("Value checked at index [%ld] = [%d]\n", current->index,
		current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}

	return (NULL);
}
