#include<stdlib.h>
#include<stdio.h>
/**
 *main - Entery point
 *Description:print all single digit numbers of base 10
 *Return:Always 0
*/
int main(void)
{
	int n;

	while (n < 10)
	{
	putchar('0' + n);
	n++;
	}
	putchar('\n');
	return (0);
}
