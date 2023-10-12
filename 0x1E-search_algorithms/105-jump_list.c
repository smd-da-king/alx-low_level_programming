#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"


/**
 * jump_list - jump list to search algorithm
 * @list: sorted list
 * @size: size of the array
 * @value: element to search
 * Return: pointer the matching node | NULL otherwise
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *left = list, *jump = list;
	size_t i = 0, step;

	if (list == NULL || size == 0)
		return (NULL);

	step = (size_t)sqrt(size);
	for (; jump->index + 1 < size && jump->n < value;)
	{
		left = jump;
		for (i += step; jump->index < i; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", i, jump->n);
	}
	printf("Value found between indexes ");
	printf("[%ld] and [%ld]\n", left->index, jump->index);

	while (left->index < jump->index && left->n < value)
	{
		printf("Value checked ");
		printf("at index [%ld] = [%d]\n", left->index, left->n);
		left = left->next;
	}
	printf("Value checked at index [%ld] = [%d]\n", left->index, left->n);
	if (left->n == value)
		return (left);
	return (NULL);
}
