#include "lists.h"
/**
 * print_listint - function that prints all the elements of a listint_t list.
 * @h : a pointer to head elements.
 * Return: its returns i the number of elements in lisiint.
 */





size_t print_listint(const listint_t *h)

{
	size_t i;

	i = 0;

	while (h)
	{
	printf("%d \n", h->n);
	h = h->next;
	i++;
	}

return (i);
}


