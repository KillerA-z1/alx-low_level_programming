#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a doubly linked list.
 * @h: Pointer to the head of the list.
 * Return: The number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t leng = 0;

	while (h != NULL)
	{
		h = h->next;
		leng++;
	}

	return (leng);
}
