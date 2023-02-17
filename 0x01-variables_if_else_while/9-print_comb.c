#include <stdio.h>
#include <unistd.h>
/**
 * main - Entry point
 * Description: prints aingle numbers must be separated by comma
 * Return: Always 0 (success)
 */
int main(void)
{
	int n = 0;

	while (n < 10)
	{
	putchar(n + '0');
	if (n != 9)
	{
	putchar(',');
	putchar(' ');
	}
	n++;
	}
	putchar('\n');
	return (0);
}
