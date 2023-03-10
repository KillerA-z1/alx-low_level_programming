#include <stdio.h>

/**
 * main - prints all arguments received
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to strings containing the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i = 0;

	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}

