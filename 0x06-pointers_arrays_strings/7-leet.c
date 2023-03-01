#include "main.h"


/**
 * leet - Encodes a string to 1337.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *leet(char *str)
{
	int i = 0;
	char c;

	while ((c = str[i]))
	{
		switch (c)
		{
			case 'a':
			case 'A':
				str[i] = '4';
				break;
			case 'e':
			case 'E':
				str[i] = '3';
				break;
			case 'o':
			case 'O':
				str[i] = '0';
				break;
			case 't':
			case 'T':
			str[i] = '7';
				break;
			case 'l':
			case 'L':
			str[i] = '1';
			break;
		}
		i++;
	}
	return (str);
}

