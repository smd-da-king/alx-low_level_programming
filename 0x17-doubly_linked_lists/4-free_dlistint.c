#include "lists.h"

/**
 * free_dlistint - free a doubly lniked lists
 * @h: head of the linked list
 */
void free_dlistint(dlistint_t *h)
{
	dlistint_t *tmp = h;

	while (h != NULL)
	{
		tmp = h->next;
		free(h);
		h = tmp;
	}
}
