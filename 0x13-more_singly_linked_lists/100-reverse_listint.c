#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 *
 * @head: A pointer to a pointer to the first node of the list.
 *
 * Return: The reversed list,if the linked list is empty return 0.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL;
	listint_t *next_node = NULL;

	if (head == NULL)
		return (0);

	while (head && *head)
	{
		next_node = (*head)->next;
		(*head)->next = prev_node;
		prev_node = *head;
		*head = next_node;
	}
	*head = prev_node;

	return (*head);
}

