#include "lists.h"

/**
 * add_nodeint - function that adds a new node at the beginning of a listint_t.
 * @head: a pointer to head.
 * @n: the value we add in n
 * Return: the new head with the pointer to second element.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_head = malloc(sizeof(listint_t));

	if (!new_head)
		return (NULL);

	new_head->n = n;
	new_head->next = *head;
	*head = new_head;

	return (*head);
}

