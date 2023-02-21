

#include <stdio.h>

/**
* numLength - returns the length of a number as a string
* @num: the number to get the length of
*
* Return: the number of digits in num
*/

	int numLength(int num)
{
	int length = 0;

	if (!num)
	return (1);

	while (num)
	{
	num = num / 10;
	length += 1;
	}

	return (length);
}

/**
* main - prints the first 98 Fibonacci numbers
*
* Return: 0
*/

int main(void)
{
	unsigned long f1 = 1, f2 = 2, tmp, mx = 100000000, f1o = 0, f2o = 0, tmpo = 0;
	short int i, initial0s;

	for (i = 1; i <= 98; i++)
	{
	if (f1o > 0)
	printf("%lu", f1o);

	initial0s = numLength(mx) - 1 - numLength(f1);

	while (f1o > 0 && initial0s > 0)
	{
	printf("%i", 0);
	initial0s--;
	}

	printf("%lu", f1);

	tmp = (f1 + f2) % mx;
	tmpo = f1o + f2o + (f1 + f2) / mx;
	f1 = f2;
	f1o = f2o;
	f2 = tmp;
	f2o = tmpo;

	if (i != 98)
	printf(", ");
	else
	printf("\n");
	}

	return (0);
}

