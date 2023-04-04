#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at at a given position.
 * @head: Pointer to the head node of the list.
 * @index: Index number of the node to be deleted.
 *
 * Return: 1 if successful, -1 if failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *temp, *node_to_delete;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		node_to_delete = *head;
		*head = (*head)->next;
		free(node_to_delete);
		return (1);
	}

	temp = *head;

	for (i = 0; i < index - 1 && temp != NULL; i++)
	{
		temp = temp->next;
	}

	if (temp == NULL || temp->next == NULL)
		return (-1);

	node_to_delete = temp->next;
	temp->next = node_to_delete->next;
	free(node_to_delete);
	return (1);
}

