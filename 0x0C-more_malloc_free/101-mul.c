#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * add - Adds two numbers as strings and returns the result as a string
 *
 * @num1: First number to add
 * @num2: Second number to add
 *
 * Return: Result of the addition as a string
 */


#include <stdlib.h>

int find_len(char *str)
{
        int len = 0;

        while (*str++)
                len++;

        return (len);
}

char *multiply(char *num1, char *num2)
{
        int len_num1 = find_len(num1);
        int len_num2 = find_len(num2);
        char *prod = malloc(len_num1 + len_num2 + 1);

        if (prod == NULL)
                exit(98);

        for (int i = 0; i < len_num1 + len_num2; i++)
                prod[i] = '0';

        prod[len_num1 + len_num2] = '\0';

        for (int i = len_num1 - 1; i >= 0; i--) {
                int carry = 0;
                char digit1 = num1[i];

                for (int j = len_num2 - 1; j >= 0; j--) {
                        char digit2 = num2[j];
                        int prod_ij = (digit1 - '0') * (digit2 - '0');
                        int sum = prod[i+j+1] - '0' + prod_ij + carry;
                        prod[i+j+1] = (sum % 10) + '0';
                        carry = sum / 10;
                }

                prod[i] += carry;
        }

        char *result = prod;

        while (*result == '0')
                result++;

        if (*result == '\0')
                result--;

        char *result_copy = malloc(find_len(result) + 1);

        if (result_copy == NULL)
                exit(98);

        for (int i = 0; i < find_len(result); i++)
                result_copy[i] = result[i];

        result_copy[find_len(result)] = '\0';

        free(prod);

        return result_copy;
}

int is_valid_number(char *num)
{
        while (*num) {
                if (*num < '0' || *num > '9')
                        return 0;

                num++;
        }

        return 1;
}

int main(int argc, char **argv)
{
        if (argc != 3) {
                char *error_msg = "Error\n";
                while (*error_msg)
                        _putchar(*error_msg++);

                exit(98);
        }

        char *num1 = argv[1];
        char *num2 = argv[2];

        if (!is_valid_number(num1) || !is_valid_number(num2)) {
                char *error_msg = "Error\n";
                while (*error_msg)
                        _putchar(*error_msg++);

                exit(98);
        }

        char *result = multiply(num1, num2);

        while (*result)
                _putchar(*result++);

        _putchar('\n');

        return 0;
}

