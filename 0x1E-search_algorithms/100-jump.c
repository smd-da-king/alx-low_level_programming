#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"


/**
 * jump_search - jump to search algorithm
 * @array: sorted array
 * @size: size of the array
 * @value: element to search
 * Return: index of the first match | -1 otherwise
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, j, low = 0, step;

	if (array == NULL || size == 0)
		return (-1);

	step = (size_t)sqrt(size);
	for (i = 0; i < size && array[i] < value; i += step)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		low = i;
	}
	printf("Value found between indexes ");
	printf("[%ld] and [%ld]\n", low, low + step);
	j = low;
	while (j < size)
	{
		printf("Value checked array[%ld] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
		j++;
	}
	return (-1);
}
