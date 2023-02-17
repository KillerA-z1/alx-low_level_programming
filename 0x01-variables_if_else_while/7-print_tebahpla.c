#include<stdio.h>
#include<stdlib.h>
/**
 *main - Entery point
 *Description:Print alphabet in lowercase,followed by a new line
 *Return: Always 0
*/
int main(void)
{
	int ch = 'z';

	while (ch >= 'a')
	{
	putchar(ch);
	ch--;
	}
	putchar('\n');

	return (0);
}
