#include "lists.h"

/**
 * listint_len - function that returns the number of elements of listint_len.
 * @h : a pointer to head elements.
 * Return: it returns i the number of elements in lisiint.
 */

size_t listint_len(const listint_t *h)
{
	size_t i;

	i = 0;

	while (h)
	{
	h = h->next;
	i++;
	}
	return (i);
}
