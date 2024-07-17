#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

/* Include the standard library for general purpose functions */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Function of mandatory tasks*/

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);

/* Function of advanced tasks*/
int exponential_search(int *array, size_t size, int target);
int binary_search_subarray(int *array, size_t start, size_t end, int target);
int advanced_binary(int *array, size_t size, int value);
#endif
