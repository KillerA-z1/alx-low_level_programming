#include "lists.h"

/**
 * free_listint2 -  Function that frees a listint_t list.
 * free_list - Frees a list_t list.
 * @head: A pointer to the list_t list.
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
	return;

	while (*head != NULL)
	{
	temp = *head;
	*head = (*head)->next;
	free(temp);
	}

	*head = NULL;
}
