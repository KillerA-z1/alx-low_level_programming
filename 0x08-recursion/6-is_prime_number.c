#include "main.h"

/**
 * check_divisibility -checks a numb is divisible by any numb from 2 to sqrt(n)
 *
 * @n: the number to check for divisibility
 * @divisor: the current divisor to check
 *
 * Return: 1 if the number is prime, otherwise 0
 */
int check_divisibility(int n, int divisor)
{
	if (n < 2 || n % divisor == 0)
		return (0);

	if (divisor * divisor > n)
		return (1);

	return (check_divisibility(n, divisor + 2));
}

/**
 * is_prime_number - checks if a number is prime
 *
 * @n: the number to check
 *
 * Return: 1 if the number is prime, otherwise 0
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	if (n == 2)
		return (1);

	if (n % 2 == 0)
		return (0);

	return (check_divisibility(n, 3));
}
