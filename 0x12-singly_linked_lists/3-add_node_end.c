#include "lists.h"
#include <string.h>

/**
 * add_node_end - a function that adds a node to the end of linked list
 * @head: pointer to a list_t pointer that points to the head struct
 * @str: pointer to string that adds as node
 *
 * Return: a pointer to new head of list, NULL on failure.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *last;
	char *string_dup;
	int len = strlen(str);

	new =  malloc(sizeof(list_t));
	if (!new)
	{
		return (NULL);
	}
	string_dup = strdup(str);
	if (!string_dup)
	{
		free(new);
		return (NULL);
	}

	new->len = len;
	new->str = string_dup;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
	}
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = new;
	}

	return (*head);
}
