#include "main.h"

/**
 * get_string_length - finds the length of a string recursively
 *
 * @str: the string to find the length of
 *
 * Return: the length of the string
 */
int get_string_length(char *str)
{
	if (*str == '\0')
		return (0);

	return (1 + get_string_length(str + 1));
}

/**
 * is_palindrome_helper - checks if a string is a palindrome recursively
 *
 * @str: the string to check
 * @len: the length of the string
 * @index: the current index being checked
 *
 * Return: 1 if the string is a palindrome, otherwise 0
 */
int is_palindrome_helper(char *str, int len, int index)
{
	if (index >= len / 2)
		return (1);

	if (str[index] == str[len - index - 1])
		return (is_palindrome_helper(str, len, index + 1));

	return (0);
}

/**
 * is_palindrome - checks if a string is a palindrome
 *
 * @str: the string to check
 *
 * Return: 1 if the string is a palindrome, otherwise 0
 */
int is_palindrome(char *str)
{
	int len = get_string_length(str);

	if (len <= 1)
		return (1);

	return (is_palindrome_helper(str, len, 0));
}

