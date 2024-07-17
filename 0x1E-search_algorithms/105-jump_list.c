#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly
 *             linked list of integers using jump search.
 * @list: A pointer to the head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jump step.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, step_size;
	listint_t *prev_node, *jump_node;

	if (list == NULL || size == 0)
		return (NULL);

	step_size = sqrt(size);
	prev_node = list;
	jump_node = list;

	while (jump_node->next != NULL && jump_node->n < value)
	{
		prev_node = jump_node;
		for (step = 0; jump_node->next != NULL && step < step_size; step++)
			jump_node = jump_node->next;

		printf("Value checked at index [%ld] = [%d]\n",
		jump_node->index, jump_node->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
	prev_node->index, jump_node->index);

	while (prev_node != NULL && prev_node->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n",
		prev_node->index, prev_node->n);
		prev_node = prev_node->next;
	}

	if (prev_node != NULL)
		printf("Value checked at index [%ld] = [%d]\n",
		prev_node->index, prev_node->n);

	return ((prev_node != NULL && prev_node->n == value) ? prev_node : NULL);
}
