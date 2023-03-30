#include "lists.h"
/**
 * print_list - Prints all of the elements of a linked list.
 * @h: Pointer to a linked list head.
 * Return: The number of total nodes in the linked list.
 */
size_t print_list(const list_t *h)
{
	int i;

	for (i = 0; h != 0; i++)
	{
	if (h->str == 0)
		printf("[0] (nil)\n");
	else
		printf("[%d] %s\n", h->len, h->str);

	h = h->next;
	}
	return (i);

}




