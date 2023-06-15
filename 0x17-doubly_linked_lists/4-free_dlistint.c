#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current, *tmp;

	current = head;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
