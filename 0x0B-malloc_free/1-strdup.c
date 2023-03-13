#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: the string to duplicate
 *
 * Return: a pointer to the newly allocated memory containing
 * a copy of the string,or NULL if str is NULL or if malloc fails.
 */

char *_strdup(char *str)
{
	char *duplicate_str;
	int i, str_len = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		str_len++;

	duplicate_str = malloc(sizeof(char) * (str_len + 1));

	if (duplicate_str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate_str[i] = str[i];

	duplicate_str[str_len] = '\0';

	return (duplicate_str);
}

