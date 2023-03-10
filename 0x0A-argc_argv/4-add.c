#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point. Adds all positive numbers passed as arguments.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the strings which are those arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
    int i, j, sum = 0;

    if (argc < 2)
    {
        printf("0\n");
        return (0);
    }

    i = 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                printf("Error\n");
                return (1);
            }
            j++;
        }
        sum += atoi(argv[i]);
        i++;
    }

    printf("%d\n", sum);
    return (0);
}

