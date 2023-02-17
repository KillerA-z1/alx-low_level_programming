#include<stdio.h>
#include<stdlib.h>
/**
 *main - Entery point
 *Description:Print alphabet in lowercase,followed by a new line except q and e
 *Return: Always 0
*/
int main(void)
{
	int ch = 'a';

	while (ch <= 'z')
	{
	if (ch == 'e' || ch == 'q')
	{
	ch++;
	}
	putchar(ch);
	ch++;
	}
	putchar('\n');

	return (0);
}

