#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t list,
 *               and returns the head node’s data (n).
 * @head: A pointer to the address of the head.
 *
 * Return: If the linked list is empty - 0.
 *         else  return data_hold (contains data of the head node)
 */

int pop_listint(listint_t **head)
{
	int data_hold;
	listint_t *temp;

	if (!*head)
		return (0);

	temp = (*head)->next;
	data_hold = (*head)->n;
	free(*head);
	*head = temp;
	return (data_hold);
}

