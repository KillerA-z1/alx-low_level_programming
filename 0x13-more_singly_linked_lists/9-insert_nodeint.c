#include "lists.h"
/**
 * insert_nodeint_at_index-Function that inserts a new node at a given position
 * @head: Pointer to the head of the list
 * @idx: The index number where the new node should be added.
 * @n: integer value to be added to the new node.
 *
 * Return: Address of the new element, NULL on failure.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *current_len = *head;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; current_len && i < idx - 1; i++)
		current_len = current_len->next;

	if (current_len == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current_len->next;
	current_len->next = new_node;

	return (new_node);
}

