#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data linked list.
 * @head: Pointer to the head of the listint_t list.
 *
 * Return: The sum of all the data (n) of the listint_t list.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	if (!head)
		return (0);

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}
