#include "lists.h"
#include <string.h>

/**
 * add_node - a function that adds a node to the head of linked list
 * @head: pointer to a list_t pointer that points to the head struct
 * @str: pointer to string that adds as node
 *
 * Return: a pointer to new head of list, NULL on failure.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	char *string_dup;
	int leng = strlen(str);

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

	pres->len = leng;
	pres->str = string_dup;
	pres->next = *head;
	*head = new;

	return (new);
}
