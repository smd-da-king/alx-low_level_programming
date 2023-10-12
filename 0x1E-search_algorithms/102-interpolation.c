#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"


/**
 * interpolation_search - for interpolation search algorithm
 * @array: sorted array
 * @size: size of the array
 * @value: element to search
 * Return: index of the match | -1 otherwise
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos = 0, low = 0, high = size - 1;

	if (array == NULL || size == 0)
		return (-1);

	while (pos < size)
	{
		pos = low +
			(((double)(high - low) /
			  (array[high] - array[low])) *
			 (value - array[low]));

		if (pos >= size)
		{
			printf("Value checked ");
			printf("array[%ld] is out of range\n", pos);
			break;
		}
		printf("Value checked ");
		printf("array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);

		if (array[pos] > value)
			high = pos - 1;
		else
			low = pos + 1;
	}
	return (-1);
}
