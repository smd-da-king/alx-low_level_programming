#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * print_array - to print array
 * @array: arary to print
 * @lo: starting index
 * @hi: end index
 */
void print_array(int *array, size_t lo, size_t hi)
{
	size_t i;

	if (lo > hi)
		return;

	printf("Searching in array: %d", array[lo]);
	for (i = lo + 1; i < hi; i++)
		printf(", %d", array[i]);

	printf("\n");
}

/**
 * binary_search_custom - binary search algorithm
 * @array: sorted array
 * @value: element to search
 * @lo: low bound
 * @hi: high bound
 * Return: index of the first match | -1 otherwise
 */
int binary_search_custom(int *array, int value, size_t lo, size_t hi)
{
	int mid;

	while (lo < hi)
	{
		print_array(array, lo, hi);
		mid = (lo + hi - 1) / 2;
		if (array[mid] == value)
			return (mid);

		if (array[mid] > value)
			hi = mid;
		else
			lo = mid + 1;
	}
	return (-1);
}

/**
 * exponential_search - exponential search algorithm
 * @array: sorted array
 * @size: size of the array
 * @value: element to search
 * Return: index of the match | -1 otherwise
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, min_right;

	if (array == NULL || size == 0)
		return (-1);
	if (array[0] == value)
		return (0);

	while (bound < size && array[bound] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	min_right = bound < size ? bound : size - 1;
	printf("Value found between ");
	printf("indexes [%ld] and [%ld]\n", bound / 2, min_right);
	return (binary_search_custom(array, value, bound / 2, min_right + 1));
}
