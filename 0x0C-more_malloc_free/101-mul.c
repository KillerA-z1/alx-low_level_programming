#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int _strlen(char *s);
void *mem_alloc(unsigned int size);
void _puts(char *s);
void _mul(char *num1, char *num2);

/**
 * _strlen - finds the length of a string
 * @s: string
 *
 * Return: length of a string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * mem_alloc - allocate memory using malloc
 * @size: size of the memory
 *
 * Return: pointer to allocated memory
 */
void *mem_alloc(unsigned int size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	return (ptr);
}

/**
 * _puts - print a string
 * @s: string
 */
void _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		putchar(s[i]);
	putchar('\n');
}

/**
 * _mul - multiplies two positive numbers
 * @num1: first number
 * @num2: second number
 */
void _mul(char *num1, char *num2)
{
	int len1, len2, i, j, n, m, sum, carry;
	char *prod;

	len1 = _strlen(num1);
	len2 = _strlen(num2);

	prod = mem_alloc(sizeof(char) * (len1 + len2 + 1));

	for (i = 0; i < len1 + len2 + 1; i++)
		prod[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n = num1[i] - '0';

		m = len2 + 1;
		for (j = len2 - 1; j >= 0; j--)
		{
			m--;
			sum = carry + (n * (num2[j] - '0')) +
				(prod[m] - '0');
			prod[m] = (sum % 10) + '0';
			carry = sum / 10;
		}

		if (carry > 0)
			prod[m - 1] += carry;
	}

	i = 0;
	while (prod[i] == '0' && i < len1 + len2 - 1)
		i++;

	_puts(&prod[i]);

	free(prod);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				exit(98);
			}
		}
	}

	if (*argv[1] == '0' || *argv[2] == '0')
	{
		_puts("0");
		return (0);
	}

	_mul(argv[1], argv[2]);

	return (0);
}

