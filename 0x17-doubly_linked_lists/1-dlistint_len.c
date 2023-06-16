#include "lists.h"

/**
 * dlistint_len - count the length of doubly lniked list
 * @h: head of the linked list
 * Return: length of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
