#include "main.h"

/**
 * leet - Encodes a string to 1337.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
	int i, j;
	char *ltr = "aAeEoOtTlL";
	char *num = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; ltr[j] != '\0'; j++)
		{
			if (str[i] == ltr[j])
			{
				str[i] = num[j];
				break;
			}
		}
	}

	return (str);
}

