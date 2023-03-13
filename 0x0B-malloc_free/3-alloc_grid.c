#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2-dimensional array of integers
 *
 * @width: the width of the grid
 * @height: the height of the grid
 *
 * Return: a pointer to the newly allocated 2-dimensional array,
 * or NULL if memory allocation fails or either width or height is 0 or -neg.
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int row = 0, col = 0;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	while (row < height)
	{
		grid[row] = malloc(sizeof(int) * width);

		if (grid[row] == NULL)
		{
			while (col < row)
			{
				free(grid[col]);
				col++;
			}

			free(grid);
			return (NULL);
		}

		while (col < width)
		{
			grid[row][col] = 0;
			col++;
		}

		row++;
		col = 0;
	}

	return (grid);
}

