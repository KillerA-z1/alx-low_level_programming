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
	list_t *pres;
	int len_;

	char *string_dup;

	pres =  malloc(sizeof(list_t));
	if (pres == NULL)
	{
		return (NULL);
	}

	string_dup = strdup(str);
	if (string_dup == NULL)
	{
		free(pres);
		return (NULL);
	}

	len_ = 0;

	while (str[len_])
	{
		len_++;
	}

	pres->len = len_;
	pres->str = string_dup;
	pres->next = *head;
	*head = pres;

	return (pres);
}
