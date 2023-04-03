#include "lists.h"

/**
 * free_listint -  Function that frees a listint_t list.
 * free_list - Frees a list_t list.
 * @head: A pointer to the list_t list.
 */

void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head)
	{
	tmp = head->next;
	free(head);
	head = tmp;
	}

}
