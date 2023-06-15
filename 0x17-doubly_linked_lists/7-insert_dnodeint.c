#include "lists.h"

/**
 * insert_dnodeint_at_index -Inserts a new node at a given position.
 * @head: Pointer to the pointer to the head of the list.
 * @ix: Index at which the new node should be inserted.
 * @v: Value of the new node.
 * Return: Address of the new node if successful, NULL otherwise.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int ix, int v)
{
	unsigned int i;
	dlistint_t *new_node, *current = *head;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = v;
	new_node->next = NULL;

	if (ix == 0)
		return (add_dnodeint(head, v));

	for (i = 0; current && i < ix; i++)
	{
		if (i == ix - 1)
		{
			if (!current->next)
				return (add_dnodeint_end(head, v));

			new_node->next = current->next;
			new_node->prev = current;
			current->next->prev = new_node;
			current->next = new_node;
			return (new_node);
		}
		current = current->next;
	}

	free(new_node);
	return (NULL);
}
