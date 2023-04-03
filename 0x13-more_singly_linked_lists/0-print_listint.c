#include "lists.h"
/**
 * print_listint - function that prints all the elements of a listint_t list.
 * @h : a pointer to head elements.
 * Return: its returns i the number of elements in lisiint.
 */

size_t print_listint(const listint_t *h)

{
	size_t i;
	const listint_t *current = h;
	/* This new pointer is then used to traverse the linked list */
	/* while keeping the original value of h unchanged*/

	for (i = 0; current != NULL; i++)
	{
	printf("%d\n", current->n);
	current = current->next;
	}

return (i);
}


