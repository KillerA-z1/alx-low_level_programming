#include "main.h"

/**
 * wildcard_match - Determines if a given string matches a wildcard pattern
 * @str: The input string to be matched
 * @pattern: The wildcard pattern to match against
 *
 * Return: 1 if the input string matches the wildcard pattern, 0 otherwise
 */

int wildcard_match(char *str, char *pattern)
{
	if (*pattern == '\0')
	{
		return (*str == '\0');
	}

	if (*pattern == '*')
	{
		return (wildcard_match(str, pattern + 1) ||
				(*str && wildcard_match(str + 1, pattern)));
	}

	if (*str == *pattern)
	{
		return (wildcard_match(str + 1, pattern + 1));
	}

	return (0);
}

/**
 * wildcmp - Compares two strings for wildcard match
 * @s1: The first input string to be matched
 * @s2: The second input string to match against
 *
 * Return: 1 if the input strings match, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	return (wildcard_match(s1, s2));
}
