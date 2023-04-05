#include "lists.h"

/**
 * print_listint_safe - Function that prints a listint_t linked list.
 * @head: A pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t i = 0;

	if (!head)
		exit(98);

	while (current)
	{
		printf("[%p] %d\n", (void *) current, current->n);
		i++;

		if (current <= current->next)
		{
			printf("-> [%p] %d\n", (void *) current->next, current->next->n);
			break;
		}

		current = current->next;
	}

	return (i);
}

