#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings up to n bytes
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of bytes to concatenate from s2
 *
 * Return: a pointer to the newly allocated space in memory which contains
 * the concatenated string, or NULL if the allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concatenated_str;
	unsigned int total_len = n, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		total_len++;

	concatenated_str = malloc(sizeof(char) * (total_len + 1));

	if (concatenated_str == NULL)
		return (NULL);

	total_len = 0;

	for (i = 0; s1[i]; i++)
		concatenated_str[total_len++] = s1[i];

	for (i = 0; s2[i] && i < n; i++)
		concatenated_str[total_len++] = s2[i];

	concatenated_str[total_len] = '\0';

	return (concatenated_str);
}

