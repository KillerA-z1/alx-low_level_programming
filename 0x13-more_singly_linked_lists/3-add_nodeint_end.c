#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to the head of the list
 * @n: integer value to be added to the new node
 *
 * Return: Address of the new element, NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	int i;
	listint_t *current_leng = *head;
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	for (i = 0; current_leng && current_leng->next; i++)
		current_leng = current_leng->next;

	new_node->n = n;
	new_node->next = NULL;
	if (current_leng == NULL)
		*head = new_node;
	else
		current_leng->next = new_node;

	return (new_node);
}
