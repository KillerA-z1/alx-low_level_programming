#include<stdio.h>
#include<stdlib.h>
/**
 *main - Entery point
 *Description:print lowercase and then in uppercase
 *Return: Always 0
*/
int main(void)
{
	int chl = 'a';
	int chA = 'A';

	while (chl <= 'z')
	{
	putchar(chl);
	chl++;
	}
	while (chA <= 'Z')
	{
	putchar(chA);
	chA++;
	}
	putchar('\n');

	return (0);
}

