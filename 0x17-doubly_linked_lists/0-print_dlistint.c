#include "lists.h"

/**
 * print_dlistint - print doubly lniked lists elements
 * @h: head of the linked list
 * Return: length of the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
