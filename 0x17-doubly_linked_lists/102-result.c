#include <stdio.h>
#include <stdbool.h>

/**
 * is_palindrome - Check if a number is a palindrome.
 * @n: The number to check.
 *
 * Return: True if the number is a palindrome, false otherwise.
 */
bool is_palindrome(int n)
{
    int reverse = 0;
    int temp = n;

    while (temp > 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }

    return n == reverse;
}

/**
 * largest_palindrome - Find the largest palindrome made from the product
 *                     of two 3-digit numbers.
 *
 * Return: The largest palindrome.
 */
int largest_palindrome()
{
    int largest_palindrome = 0;

    for (int i = 100; i < 1000; i++)
    {
        for (int j = i; j < 1000; j++)
        {
            int product = i * j;
            if (is_palindrome(product) && product > largest_palindrome)
            {
                largest_palindrome = product;
            }
        }
    }

    return largest_palindrome;
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main()
{
    int result = largest_palindrome();

    FILE *file = fopen("102-result", "w");
    if (file != NULL)
    {
        fprintf(file, "%d", result);
        fclose(file);
    }

    return 0;
}
