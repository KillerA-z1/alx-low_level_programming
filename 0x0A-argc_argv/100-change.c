#include <stdio.h>
#include <stdlib.h>

/**
 * main - Calculates the minimum number of coins to make change
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[])
{
	int cents, coins_used = 0, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = cents; i > 0;)
	{
		switch (i >= 25 ? 25 : i >= 10 ? 10 : i >= 5 ? 5 : i >= 2 ? 2 : 1)
		{
			case 25:
				i -= 25;
				coins_used++;
				break;
			case 10:
				i -= 10;
				coins_used++;
				break;
			case 5:
				i -= 5;
				coins_used++;
				break;
			case 2:
				i -= 2;
				coins_used++;
				break;
			case 1:
				i -= 1;
				coins_used++;
				break;
		}
	}
	printf("%d\n", coins_used);
	return (0);
}
