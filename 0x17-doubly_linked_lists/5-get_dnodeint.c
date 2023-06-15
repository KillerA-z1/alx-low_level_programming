#include "lists.h"

/**
 * get_dnodeint_at_index -Retrieves node at a given index in a dub linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the desired node.
 * Return: Pointer to the node at the given index, or NULL if it doesn't exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (index > 0 && head != NULL)
	{
		head = head->next;
		index--;
	}

	return (head);
}
