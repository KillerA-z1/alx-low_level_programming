#include <stdio.h>

/**
 * main - Entry point. Prints the number of arguments passed to the program.
 * @argc: The number of arguments passed.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}

