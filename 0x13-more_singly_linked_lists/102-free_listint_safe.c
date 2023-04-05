#include "lists.h"

/**
 * free_listint_safe - Function that frees a listint_t list.
 *
 * @h: A pointer to a pointer to the first node of the list.
 *
 * Return: The size of the list that was free'd.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i = 0;
	listint_t *current = *h, *tmp = NULL;

	while (current)
	{
		i++;
		tmp = current;
		current = current->next;
		free(tmp);
		if (tmp <= current)
		{
			*h = NULL;
			break;
		}
	}

	return (i);
}

