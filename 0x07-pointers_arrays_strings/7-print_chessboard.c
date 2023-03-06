#include "main.h"

/**
 * print_chessboard - Prints a chessboard.
 * @a: The chessboard to print.
 */

void print_chessboard(char (*a)[8])
{
	int indx1 = 0, indx2;

	while (a[indx1][7])
	{
		indx2 = 0;
		while (indx2 < 8)
		{
			_putchar(a[indx1][indx2]);
			indx2++;
		}
		_putchar('\n');
		indx1++;
	}
}

